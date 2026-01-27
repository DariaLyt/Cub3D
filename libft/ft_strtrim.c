/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvync <dlytvync@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:57:43 by dlytvync          #+#    #+#             */
/*   Updated: 2025/04/23 10:38:38 by dlytvync         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*str_start;
	const char	*str_end;
	size_t		len;
	char		*res;

	if (!s1 || !set)
		return (NULL);
	str_start = s1;
	str_end = s1 + ft_strlen(s1) - 1;
	len = 0;
	while (*str_start && in_set(*str_start, set))
		str_start++;
	while (*str_end && in_set(*str_end, set))
		str_end--;
	if (str_end >= str_start)
		len = str_end - str_start + 1;
	res = malloc (len + 1);
	if (!res)
		return (NULL);
	res = ft_strncpy(res, str_start, len);
	return (res);
}
