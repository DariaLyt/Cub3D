#include "cub.h"

void    handle_rotation(t_game *game)
{
    if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
        game->player.angle -= game->player.speed;
    if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
        game->player.angle += game->player.speed;
}