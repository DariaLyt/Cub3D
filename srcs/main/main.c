#include "cub.h"

void	game_loop(void *data)
{
	t_game *game;
	game = (t_game *)data;
	render(game);
	handle_movement(game);
	handle_rotation(game);

	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}

int execution(t_game *game)
{
	if (!init_game(game))
        return (0);
    mlx_image_to_window(game->mlx, game->image, 0, 0);
	printf("execution1\n");
	// game->player.pos_x= 26;
	// game->player.pos_y = 11;
    mlx_loop_hook(game->mlx, game_loop, game);
    mlx_loop(game->mlx);
    mlx_terminate(game->mlx);
    //ft_putstr_fd("Hello world!", 1);
	return (1);
}

int	run_game(char *map_name, t_game *game)
{
	// game = malloc(sizeof(t_game));
	// if (!game)
		// return (0);
	init_game_struct(game);
	if(parsing(map_name, game) == INVALID)
		return(INVALID); // error and cleanup
	print_game_data(game); // << debug print // delete me when done
	// execution();
	if (!execution(game))
	{
		free_map(game);
		return (INVALID);
	}
		free_map(game);
		return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2 && argv[1][0])
		run_game(argv[1], &game);
	else
		printf("doofus");
	return (0);
}
