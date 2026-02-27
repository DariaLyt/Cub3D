/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:36:43 by pnurmi            #+#    #+#             */
/*   Updated: 2026/02/27 09:36:44 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_png(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5)
		return (0);
	if (ft_strncmp(path + len - 4, ".png", 4) == 0)
		return (1);
	return (0);
}

int	is_space(char c)
{
	int	i;

	i = 0;
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	is_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			return (0);
		i++;
	}
	if (i > 0)
		return (1);
	return (0);
}

int	is_valid_map_line(char *line)
{
	while (*line)
	{
		if (is_valid_char(*line) == INVALID)
			return (INVALID);
		line++;
	}
	return (SUCCESS);
}

int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == '\n' || c == 'N' || c == 'E'
		|| c == 'S' || c == 'W')
		return (SUCCESS);
	return (INVALID);
}
