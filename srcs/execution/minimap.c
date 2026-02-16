#include "cub.h"

void draw_minimap_rays(t_game *game)
{   
    double ray_x;
    double ray_y;
    double x;
    double y;
    double angle;

    angle = game->player.angle;;
    while(angle <= (game->player.angle))
    {
        ray_x = game->player.pos_x;
        ray_y = game->player.pos_y;
        while (!is_wall(game, ray_x, ray_y))
        {
            ray_x += cos(angle) * STEP_SIZE;
            ray_y += sin(angle) * STEP_SIZE;
            x = ray_x * MINIMAP_SCALE;
            y = ray_y * MINIMAP_SCALE;
            if (x >= 0 && x < game->width && y >= 0 && y < game->height)
                mlx_put_pixel(game->image, (int)x, (int)y, mk_col(255,0,0));
        }
        angle += 0.001;
    }
}

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
            // if (game->map.grid[y][x] == 'E')
            // {
            //     game->player.pos_x = x;
            //     game->player.pos_y = y;
            // }
            draw_mini_square(game, screen_x, screen_y, MINIMAP_SCALE);
            x++;
        }
        y++;
    }
    //printf("\npllayer x = %f, y = %f", game->player.pos_x, game->player.pos_y);
}

void    draw_player(t_game *game)
{
    int x;
    int y;
    int size;
    int i;
    int j;

    x = (int)(game->player.pos_x * MINIMAP_SCALE);
    y = (int)(game->player.pos_y * MINIMAP_SCALE);
    size = 5;
    i = -size / 2;
    while (i <= size/2)
    {
        j = -size/2;
        while(j <= size/2)
        {
            if (x+i >= 0 && x + i < game->width && y+ j >= 0 && y + j < game->height)
            {
                mlx_put_pixel(game->image, x + i, y + j, mk_col(255,0,0));
            }
            j++;
        }
        i++;
    }

}
