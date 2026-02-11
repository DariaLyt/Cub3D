#include "cub.h"

void    draw_floor_ceiling(t_game *game)
{
    int h;
    int w;
    h = 0;
    while (h < game->height)
    {
        w = 0;
        while (w < game->width)
        {
            if (h < game->height / 2)
                mlx_put_pixel(game->image, w, h, game->ceiling);
            else
                mlx_put_pixel(game->image, w, h, game->floor);
            w++;
        }
        h++;
    }
}
void    draw_walls(game)
{
    
}

void    render(t_game *game)
{
    draw_floor_ceiling(game);
    draw_minimap(game);
    draw_player(game);
    //draw_walls(game);
}