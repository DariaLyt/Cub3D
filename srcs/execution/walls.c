#include "cub.h"

double	calc_delta(double dir)
{
	if (dir == 0.0)
		return (1e30);
	return (fabs(1.0 / dir));
}

void init_dda(t_game *game, double angle, t_dda *dda)
{
    double player_x;
    double player_y;
    int map_x;
    int map_y;

    player_x = game->player.pos_x;
    player_y = game->player.pos_y;
    map_x = (int)player_x;
    map_y = (int)player_y;

    game->ray.dir_x = cos(angle);
    game->ray.dir_y = sin(angle); 
    dda->delta_x = calc_delta(game->ray.dir_x);
	if (game->ray.dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_x = (player_x - map_x) * dda->delta_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_x = (map_x + 1.0 - player_x) * dda->delta_x;
	}

    dda->delta_y = calc_delta(game->ray.dir_y);
	if (game->ray.dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_y = (player_y - map_y) * dda->delta_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_y = (map_y + 1.0 - player_y) * dda->delta_y;
	}
    dda->map_x = map_x;
    dda->map_y = map_y;
}

void	perform_dda(t_game *game, t_dda *dda)
{
	while (1)
	{
		if (dda->side_x < dda->side_y)
		{
			dda->side_x += dda->delta_x;
			dda->map_x += dda->step_x;
			game->ray.side = 0;
		}
		else
		{
			dda->side_y += dda->delta_y;
			dda->map_y += dda->step_y;
			game->ray.side = 1;
		}
        if (game->map.grid[dda->map_y][dda->map_x] == '1')
            break;
	}
}
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
    int j = game->wall.visible_start;
    while (j <= game->wall.visible_end)
    {
        mlx_put_pixel(game->image, x, j, mk_col(255, 0, 255));
        j++;
    }
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