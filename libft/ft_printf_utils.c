/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvync <dlytvync@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:51:23 by dlytvync          #+#    #+#             */
/*   Updated: 2025/05/29 11:48:05 by dlytvync         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int *count, int *error)
{
	if (*error == -1)
		return ;
	if (write(1, &c, 1) < 1)
		*error = -1;
	else
		*count += 1;
}

void	ft_putstr(char *s, int *count, int *error)
{
	if (!s)
		s = "(null)";
	while (*s)
	{
		ft_putchar(*s, count, error);
		if (*error == -1)
			return ;
		s++;
	}
}

void	ft_putnbr(long n, int *count, int *error)
{
	if (n < 0)
	{
		ft_putchar('-', count, error);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10, count, error);
	if (*error == -1)
		return ;
	ft_putchar(n % 10 + '0', count, error);
}

void	ft_putnbr_hex(unsigned long n, int up, int *count, int *error)
{
	char	*base;

	if (up)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		ft_putnbr_hex(n / 16, up, count, error);
	if (*error == -1)
		return ;
	ft_putchar(base[n % 16], count, error);
}

void	ft_putptr(void *ptr, int *count, int *error)
{
	unsigned long	address;

	address = (unsigned long)ptr;
	if (ptr == NULL)
	{
		ft_putstr("(nil)", count, error);
		return ;
	}
	ft_putstr("0x", count, error);
	if (*error == -1)
		return ;
	ft_putnbr_hex(address, 0, count, error);
}
