/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parsing_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:35:54 by pnurmi            #+#    #+#             */
/*   Updated: 2026/02/27 10:33:19 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_valid_ext(char *map_name)
{
	size_t	len;

	if (!map_name)
		return (INVALID);
	len = ft_strlen(map_name);
	if (len < 5 || ft_strncmp(&map_name[len - 4], ".cub", 4) != 0)
		return (printf("Error: Invalid file extension\n"), INVALID);
	return (SUCCESS);
}

int	parse_line(t_game *game, char *line)
{
	if (game->map.meta_count < 6)
	{
		if (is_empty_line(line))
			return (SUCCESS);
		if (is_metadata(game, line) == SUCCESS)
		{
			game->map.meta_count++;
			return (SUCCESS);
		}
		printf("Error: Missing metadata or invalid identifier\n");
		return (INVALID);
	}
	add_to_map_list(game, line);
	return (SUCCESS);
}

int	parse_file(t_game *game, int fd)
{
	char	*line;
	int		status;

	status = SUCCESS;
	game->map.meta_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		status = parse_line(game, line);
		free(line);
		if (status == INVALID)
		{
			empty_gnl_stash(fd);
			return (INVALID);
		}
		line = get_next_line(fd);
	}
	if (game->map.meta_count != 6)
		return (printf("Error: Metadata missing\n"), INVALID);
	if (!game->map.temp_list)
		return (printf("Error: Map missing\n"), INVALID);
	return (SUCCESS);
}

void	empty_gnl_stash(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}
