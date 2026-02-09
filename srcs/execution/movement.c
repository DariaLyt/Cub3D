#include "cub.h"

void    handle_movement(t_game *game)
{
    double  x;
    double  y;

    if (!movement_delta(game, &x, &y))
    {
        game->player_moving = false;
        return ;
    }
//    player_move(game, x, y);
}

int movement_delta(t_game *game, double *x, double *y)
{
    if (mlx_is_key_down(game->mlx, MLX_KEY_W))
    {
        *x = cos(game->player.angle) * game->player.speed;
        *y = sin(game->player.angle) * game->player.speed;
    }
    else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
    {
        *x = -cos(game->player.angle) * game->player.speed;
        *y = -sin(game->player.angle) * game->player.speed;
    }
    else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
    {
        *x = -sin(game->player.angle) * game->player.speed;
        *y = cos(game->player.angle) * game->player.speed;
    }
    else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
    {
        *x = sin(game->player.angle) * game->player.speed;
        *y = -cos(game->player.angle) * game->player.speed;
    }
    else 
        return (0);
    return (1);
}

void    player_move(t_game *game, double x, double y)
{
    double old_x;
    double old_y;

    old_x = game->player.pos_x;
    old_y = game->player.pos_y;
   // if ()
}