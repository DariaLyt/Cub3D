#include "cub.h"

void draw_mini_square(t_game *game, int x, int y, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if ((x + i) >= 0 && (x + i) < game->width && (y + j) >= 0 && (y + j) < game->height)
            {
                mlx_put_pixel(game->image, x+i, y+j, game->mini_color);
            }
            j++; 
        }
        i++;
    }
}

uint32_t mk_col(unsigned char r, unsigned char g, unsigned char b)
{
    return (0xFF | b << 8 | g << 16 | r << 24);
}

void draw_minimap(t_game *game)
{
    int x;
    int y;
    int screen_x;
    int screen_y;


    game->mini_color = 0;
    y = 0;
    while (game->map.grid[y])
    {
        x = 0;
        while (game->map.grid[y][x])
        {
            screen_x = x * MINIMAP_SCALE;
            screen_y = y * MINIMAP_SCALE;
            if (game->map.grid[y][x] == '1')
            {
                game->mini_color = mk_col(0, 0, 255);
            }
            else if (game->map.grid[y][x] == '0')
            {
                game->mini_color = 16400995;
            }
            draw_mini_square(game, screen_x, screen_y, MINIMAP_SCALE);
            x++;
        }
        y++;
    }
}
