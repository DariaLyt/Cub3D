#include <stdio.h>
#include "libft.h"
#include "cub.h"

void    game_loop(void *data)
{
    t_game  *game;
    game = (t_game *)data;

    //movement
    handle_movement(game);
    //rotation
    //render
    render(game);
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(game->mlx);
}

int main()
{
    t_game game;
    if (!init_game(&game))
        return (0);
    mlx_image_to_window(game.mlx, game.image, 0, 0);
    mlx_loop_hook(game.mlx, game_loop, &game);
    mlx_loop(game.mlx);
    mlx_terminate(game.mlx);
    ft_putstr_fd("Hello world!", 1);
    return (1);
}