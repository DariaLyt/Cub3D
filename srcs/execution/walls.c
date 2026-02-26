#include "cub.h"

void	compute_hit(t_game *game, double angle, t_dda *dda)
{
	double	dist;

	if (game->ray.side == 0)
	{
		dist = (dda->map_x - game->player.pos_x + (1 - dda->step_x) / 2) / game->ray.dir_x;
		game->ray.hit_y = game->player.pos_y + dist * game->ray.dir_y;
		game->ray.wall_x = game->ray.hit_y - floor(game->ray.hit_y);
	}
	else
	{
		dist = (dda->map_y - game->player.pos_y + (1 - dda->step_y) / 2) / game->ray.dir_y;
		game->ray.hit_x = game->player.pos_x + dist * game->ray.dir_x;
		game->ray.wall_x = game->ray.hit_x - floor(game->ray.hit_x);
	}
	game->ray.distance = dist * cos(angle - game->player.angle);
}

void    calculate_ray(t_game *game, double ray)
{
   t_dda dda;

   init_dda(game, ray, &dda);
   perform_dda(game, &dda);
   compute_hit(game, ray, &dda);
   game->ray.texture = get_texture(game);
}

void    draw_wall_tile(t_game *game, double ray, int x)
{
    int y;

    calculate_ray(game, ray);
    game->wall.height = (int)(game->height / game->ray.distance);
    y = (int)(game->height / 2);
    game->wall.original_start = y - (game->wall.height / 2);
    game->wall.original_end = y + (game->wall.height / 2);
    game->wall.visible_start = game->wall.original_start;
    game->wall.visible_end = game->wall.original_end;
    if (game->wall.visible_start < 0)
        game->wall.visible_start = 0;
    if (game->wall.visible_end >= game->height)
        game->wall.visible_end = game->height - 1;
    draw_wall_texture(game, x);
}


void    draw_walls(t_game *game)
{
    double  plane;
    double  x;
    double  offset;
    double  angle;
    double  ray;

    plane = ((double)game->width / 2.0);
    x = 0;
    while ((int)x < game->width)
    {
        offset = (x + 0.5) - (double)((double)game->width / 2.0);
        angle = atan(offset / plane);
        ray = game->player.angle + angle;
        draw_wall_tile(game, ray, (int)x);
        x++;
    }
}
