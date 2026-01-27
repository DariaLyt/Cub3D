/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvync <dlytvync@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:45:14 by dlytvync          #+#    #+#             */
/*   Updated: 2025/05/29 11:47:29 by dlytvync         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

size_t	gnl_len_to_c(const char *s, char c)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	if ((char)c == '\0')
		return ((char *)(s + gnl_len_to_c(s, '\0')));
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

void	*gnl_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (s < d && s + len > d)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		if (!d && !s)
			return (NULL);
		while (len--)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}
