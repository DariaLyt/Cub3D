/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvync <dlytvync@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:40:14 by dlytvync          #+#    #+#             */
/*   Updated: 2025/04/16 11:28:55 by dlytvync         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*array;

	total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size)
		return (NULL);
	array = malloc(total);
	if (!array)
		return (NULL);
	ft_memset(array, 0, total);
	return (array);
}
