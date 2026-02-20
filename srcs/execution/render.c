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
       // printf("resize1\n");
		mlx_delete_image(game->mlx, game->image);
        //printf("resize2\n");
		game->image = mlx_new_image(game->mlx, game->new_w, game->new_h);
        //printf("resize3\n");
		mlx_image_to_window(game->mlx, game->image, 0, 0);
        //printf("resize4\n");
		game->player.speed = (double)game->height * SPEED;
		game->is_resizing = false;
	}
    printf("a1\n");
    draw_floor_ceiling(game);
    printf("a2\n");
    draw_walls(game);
    printf("a3\n");
    draw_minimap(game);
    printf("a4\n");
    draw_player(game);
    printf("a5\n");
    draw_minimap_rays(game);
    printf("a6\n");

}