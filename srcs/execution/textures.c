/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvync <dlytvync@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:09:08 by dlytvync          #+#    #+#             */
/*   Updated: 2026/02/26 12:09:09 by dlytvync         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	select_tex_x(t_ray *ray)
{
	int	tex_x;

	tex_x = ray->wall_x * ray->texture->width;
	if (tex_x >= (int)ray->texture->width)
		tex_x = ray->texture->width - 1;
	return (tex_x);
}

static int	select_tex_y(t_game *game, int y)
{
	int	relative_y;
	int	tex_height;
	int	wall_height;
	int	tex_y;

	relative_y = y - game->wall.original_start;
	tex_height = game->ray.texture->height;
	wall_height = game->wall.height;
	tex_y = (relative_y * tex_height) / wall_height;
	if (tex_y >= tex_height)
		tex_y = tex_height - 1;
	return (tex_y);
}

uint32_t	get_texture_color(mlx_texture_t *texture, int x, int y)
{
	if (x < 0 || x >= (int)texture->width || y < 0 || y >= (int)texture->height)
		return (0);
	return (*(uint32_t *)(texture->pixels + y * texture->width * 4 + x * 4));
}

mlx_texture_t	*get_texture(t_game *game)
{
	if (game->ray.side == 0)
	{
		if (game->ray.dir_x > 0)
			return (game->texture.east);
		else
			return (game->texture.west);
	}
	else
	{
		if (game->ray.dir_y > 0)
			return (game->texture.south);
		else
			return (game->texture.north);
	}
}

void	draw_wall_texture(t_game *game, int x)
{
	int			y;
	int			tex_x;
	int			tex_y;
	uint32_t	color;

	tex_x = select_tex_x(&game->ray);
	y = game->wall.visible_start;
	while (y <= game->wall.visible_end)
	{
		tex_y = select_tex_y(game, y);
		color = get_texture_color(game->ray.texture, tex_x, tex_y);
		mlx_put_pixel(game->image, x, y, color);
		y++;
	}
}
