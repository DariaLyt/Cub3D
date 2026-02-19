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
                mlx_put_pixel(game->image, w, h, game->map.floor_col);
            else
                mlx_put_pixel(game->image, w, h, game->map.ceiling_col);
            w++;
        }
        h++;
    }
}

void    resize_call(int width, int height, void *data)
{
    t_game *game;
    game = (t_game *)data;
    if (width <= MIN_WIDTH || height <= MIN_HEIGHT)
    {
        if (width == MIN_WIDTH && height == MIN_HEIGHT)
            return ;
        if (width <= MIN_WIDTH)
            game->new_w = MIN_WIDTH;
        if (height <= MIN_HEIGHT)
            game->new_h = MIN_HEIGHT;
        else
            game->new_h = height;
    }
    else
    {
        game->new_w = width;
        game->new_h = height;
    }
    game->is_resizing = true;
}

void    render(t_game *game)
{
    mlx_resize_hook(game->mlx, &resize_call, (void *)game);
    if (game->is_resizing)
	{
		game->width = game->new_w;
		game->height = game->new_h;
		mlx_delete_image(game->mlx, game->image);
		game->image = mlx_new_image(game->mlx, game->new_w, game->new_h);
		mlx_image_to_window(game->mlx, game->image, 0, 0);
		game->player.speed = (double)game->height * SPEED;
		game->is_resizing = false;
	}
    draw_floor_ceiling(game);
    draw_walls(game);
    draw_minimap(game);
    draw_player(game);
    draw_minimap_rays(game);

}