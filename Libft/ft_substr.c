/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvync <dlytvync@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:54:55 by dlytvync          #+#    #+#             */
/*   Updated: 2025/04/18 11:15:12 by dlytvync         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	lenght;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	lenght = ft_strlen(s);
	if (len == 0 || start >= lenght)
		return (ft_calloc(1, 1));
	if ((lenght - start) < len)
		len = lenght - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[len] = '\0';
	return (str);
}
