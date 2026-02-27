/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parsing_meta.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:36:26 by pnurmi            #+#    #+#             */
/*   Updated: 2026/02/27 12:00:36 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_metadata(t_game *game, char *line)
{
	char	*trimmed;

	trimmed = skip_spaces(line);
	if (ft_strncmp(trimmed, "NO ", 3) == SUCCESS)
		return (save_path(&game->map.no_path, trimmed + 3));
	if (ft_strncmp(trimmed, "SO ", 3) == SUCCESS)
		return (save_path(&game->map.so_path, trimmed + 3));
	if (ft_strncmp(trimmed, "EA ", 3) == SUCCESS)
		return (save_path(&game->map.ea_path, trimmed + 3));
	if (ft_strncmp(trimmed, "WE ", 3) == SUCCESS)
		return (save_path(&game->map.we_path, trimmed + 3));
	if (ft_strncmp(trimmed, "F ", 2) == SUCCESS)
		return (save_color(&game->map.floor_col, trimmed + 2));
	if (ft_strncmp(trimmed, "C ", 2) == SUCCESS)
		return (save_color(&game->map.ceiling_col, trimmed + 2));
	return (INVALID);
}

int	save_path(char **dest, char *src)
{
	char	*path;

	if (*dest != NULL)
		return (INVALID);
	path = ft_strtrim(src, " \n\t");
	if (!path)
		return (INVALID);
	if (path[0] == '\0')
	{
		free(path);
		return (INVALID);
	}
	*dest = path;
	return (SUCCESS);
}

int	assign_rgb(char **m_str)
{
	int		rgb;
	char	*pos;

	pos = *m_str;
	while (*pos && (*pos == ' ' || *pos == '\t'))
		pos++;
	if (!ft_isdigit(*pos))
		return (-1);
	rgb = ft_atoi(pos);
	while (*pos && ft_isdigit(*pos))
		pos++;
	while (*pos && (*pos == ' ' || *pos == '\t'))
		pos++;
	if (*pos == ',')
		pos++;
	*m_str = pos;
	return (rgb);
}

int	is_rgb_format(char *str)
{
	int	i;
	int	comma_count;

	i = 0;
	comma_count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma_count++;
		if (!ft_isdigit(str[i]) && str[i] != ',' && !is_space(str[i]))
			return (INVALID);
		i++;
	}
	if (comma_count != 2)
		return (INVALID);
	return (SUCCESS);
}

int	save_color(int *dest, char *src)
{
	char	*path;
	char	*tmp;
	int		r;
	int		g;
	int		b;

	if (*dest != -1)
		return (INVALID);
	path = ft_strtrim(src, " \n\t");
	if (!path)
		return (INVALID);
	if (is_rgb_format(path) == INVALID)
		return (free(path), INVALID);
	tmp = path;
	r = assign_rgb(&tmp);
	g = assign_rgb(&tmp);
	b = assign_rgb(&tmp);
	while (*tmp && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	if (r == -1 || g == -1 || b == -1 || r > 255 || g > 255 || b > 255)
		return (free(path), INVALID);
	free(path);
	*dest = (0xFF | b << 8 | g << 16 | r << 24);
	return (SUCCESS);
}
