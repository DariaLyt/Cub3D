#include "cub.h"

void    calculate_ray(t_game *game, double ray)
{
    /*
        perform dda in here 
        find a place where ray hits walls
    */
}

void    draw_wall_tile(t_game *game, double ray, int x)
{
    int y;

    //calculate_ray(game, ray);
    game->wall.height = (int)(game->height);/// game->ray.distance);
    y = (int)(game->height / 2);
    game->wall.original_start = y - (game->wall.height / 2);
    game->wall.original_end = y + (game->wall.height / 2);
    game->wall.visible_start = game->wall.original_start;
    game->wall.visble_end = game->wall.original_end;
    if (game->wall.visible_start < 0)
        game->wall.visible_start = 0;
    if (game->wall.visble_end >= game->height)
        game->wall.visble_end = game->height - 1;
    int j = game->wall.visible_start;
    while (j <= game->wall.visble_end)
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

    plane = (double)game->width / 2.0;
    x = 0;
    while ((int)x < game->width)
    {
        offset = (x + 0.5) - (double)game->width / 2.0;
        angle = atan(offset / plane);
        ray = game->player.angle + angle;
        draw_wall_tile(game, ray, (int)x);
        x++;
    }
}