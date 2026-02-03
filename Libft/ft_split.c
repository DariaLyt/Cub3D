/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvync <dlytvync@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:52:59 by dlytvync          #+#    #+#             */
/*   Updated: 2025/04/23 16:29:17 by dlytvync         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	word_counter(char const *s, char c )
{
	size_t	count;
	size_t	new;

	count = 0;
	new = 1;
	while (*s)
	{
		if (*s == c)
		{
			new = 1;
			s++;
			continue ;
		}
		if (new == 1)
		{
			new = 0;
			count++;
		}
		s++;
	}
	return (count);
}

static char	**ft_free(char **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	len;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = word_counter(s, c);
	array = (char **)malloc((size + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (*s == c && *s != '\0')
			s++;
		len = word_len(s, c);
		array[i] = (char *)ft_calloc((len + 1), sizeof(char));
		if (!array[i])
			return (ft_free(array, i));
		ft_memcpy(array[i++], s, len);
		s = ft_strchr(s, c);
	}
	array[size] = 0;
	return (array);
}
