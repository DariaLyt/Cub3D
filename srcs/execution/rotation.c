#include "cub.h"

void    handle_mouse_rotation(t_game *game)
{
    if (game->mouse == 1)
    {
        mlx_get_mouse_pos(game->mlx, &game->mouse_x, &game->mouse_y);
        if (game->mouse_x < game->width / 2)
            game->player.angle -= MOUSE_SENSITIVITY;
        if (game->mouse_x > game->width / 2)
            game->player.angle += MOUSE_SENSITIVITY;
        mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
        mlx_set_mouse_pos(game->mlx, game->width/2, game->height /2 );
    }
}

void    handle_rotation(t_game *game)
{
    if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
        game->player.angle -= game->player.speed;
    if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
        game->player.angle += game->player.speed;
    if (mlx_is_mouse_down(game->mlx, MLX_MOUSE_BUTTON_MIDDLE))
    {
        if (game->mouse == 0)
            game->mouse = 1;
        else 
            game->mouse = 0;
    }
}

