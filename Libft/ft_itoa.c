/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvync <dlytvync@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:28:36 by dlytvync          #+#    #+#             */
/*   Updated: 2025/04/18 11:15:40 by dlytvync         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_size(long int num)
{
	size_t	size;

	size = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		size++;
		num /= 10;
	}
	return (size);
}

static void	fill_res(char *res, long int num, size_t size, int neg)
{
	while (num > 0)
	{
		size--;
		res[size + neg] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	size;
	int		neg;
	long	num;

	num = n;
	neg = 0;
	if (num < 0)
	{
		num *= -1;
		neg = 1;
	}
	size = num_size(num);
	res = (char *)malloc((size + neg + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (num == 0)
		res[0] = '0';
	res[size + neg] = '\0';
	fill_res(res, num, size, neg);
	if (neg == 1)
		res[0] = '-';
	return (res);
}
