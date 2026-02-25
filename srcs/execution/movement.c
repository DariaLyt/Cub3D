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
    player_move(game, x, y);
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

int is_wall(t_game *game, double x, double y)
{
    char    tile;
    int nx;
    int ny;

    nx = (int)x;
    ny = (int)y;
    if (ny < 0 || ny >= game->map.height)
        return (1);
    if (nx < 0 || nx >= game->map.width)
        return (1);
    if (game->map.grid[ny][nx] == '1')
        return (1);
    return (0);
}

int can_move(t_game *game, double x, double y)
{
    double diagonal;

    diagonal = COLLISION / sqrt(2);
    if (is_wall(game, x + COLLISION, y))
        return (0);
    if (is_wall(game, x, y + COLLISION))
        return (0);
    if (is_wall(game, x - COLLISION, y))
        return (0);
    if (is_wall(game, x, y - COLLISION))
        return (0);
    if (is_wall(game, x + diagonal, y + diagonal))
        return (0);
    if (is_wall(game, x - diagonal, y + diagonal))
        return (0);
    if (is_wall(game, x + diagonal, y - diagonal))
        return (0);
    if (is_wall(game, x - diagonal, y - diagonal))
        return (0);
    return (1);
}

void    player_move(t_game *game, double x, double y)
{
    double old_x;
    double old_y;

    old_x = game->player.pos_x;
    old_y = game->player.pos_y;
    printf("player x = %f, y = %f\n", game->player.pos_x, game->player.pos_y);
    if (can_move(game, x + old_x, y + old_y))
    {
        game->player.pos_x = x + old_x;
        game->player.pos_y = y + old_y;
        game->player_moving = true;
    }
    else
    {
        if (can_move(game, x + old_x, old_y))
        {
            game->player.pos_x = x + old_x;
            game->player_moving = true;
        }
        if (can_move(game, old_x, y + old_y))
        {
            game->player.pos_y = y + old_y;
            game->player_moving = true;
        }
    }
}
