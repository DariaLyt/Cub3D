/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:36:20 by pnurmi            #+#    #+#             */
/*   Updated: 2026/02/27 14:32:08 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	game_loop(void *data)
{
	t_game	*game;

	game = (t_game *)data;
	render(game);
	handle_movement(game);
	handle_rotation(game);
	handle_mouse_rotation(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}

int	execution(t_game *game)
{
	if (!init_game(game))
		return (0);
	mlx_image_to_window(game->mlx, game->image, 0, 0);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (1);
}

int	run_game(char *map_name, t_game *game)
{
	init_game_struct(game);
	if (parsing(map_name, game) == INVALID)
		return (INVALID);
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
