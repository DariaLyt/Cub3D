/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:08:28 by dlytvync          #+#    #+#             */
/*   Updated: 2026/02/27 14:37:07 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	load_texture(char *path, mlx_texture_t **texture)
{
	*texture = mlx_load_png(path);
	if (!*texture)
		return (0);
	return (1);
}

int	init_textures(t_game *game, t_texture *text)
{
	int	check[5];

	check[0] = load_texture(game->map.ea_path, &text->east);
	check[1] = load_texture(game->map.no_path, &text->north);
	check[2] = load_texture(game->map.we_path, &text->west);
	check[3] = load_texture(game->map.so_path, &text->south);
	if (!check[0] || !check[1] || !check[2] || !check[3])
	{
		ft_putstr_fd("Failed to load textures\n", 2);
		return (0);
	}
	return (1);
}

int	init_mlx(t_game *game)
{
	int			monitor_width;
	int			monitor_height;
	t_texture	*text;

	text = &game->texture;
	if (!init_textures(game, text))
		return (0);
	game->mlx = mlx_init(MIN_WIDTH, MIN_HEIGHT, "Cub3D", true);
	if (!game->mlx)
	{
		ft_putstr_fd("Failed to initialize mlx", 1);
		return (0);
	}
	mlx_get_monitor_size(0, &monitor_width, &monitor_height);
	game->width = monitor_width / 2;
	game->height = monitor_height / 2;
	mlx_set_window_size(game->mlx, game->width, game->height);
	mlx_set_window_limit(game->mlx, MIN_WIDTH, MIN_HEIGHT,
		monitor_width, monitor_height);
	return (1);
}

void	init_player_angle(t_game *game)
{
	if (game->player.direction == 'E')
		game->player.angle = 0;
	if (game->player.direction == 'W')
		game->player.angle = M_PI;
	if (game->player.direction == 'N')
		game->player.angle = 3 * M_PI / 2;
	if (game->player.direction == 'S')
		game->player.angle = M_PI / 2;
}

int	init_game(t_game *game)
{
	game->player.speed = 0.025;
	init_player_angle(game);
	game->mouse = 0;
	game->is_resizing = false;
	if (!init_mlx(game))
		return (0);
	game->image = mlx_new_image(game->mlx, game->width, game->width);
	if (!game->image)
	{
		ft_printf("Failed mlx image\n");
		return (0);
	}
	return (1);
}
