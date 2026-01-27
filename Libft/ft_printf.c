/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvync <dlytvync@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:00:07 by dlytvync          #+#    #+#             */
/*   Updated: 2025/05/29 11:47:46 by dlytvync         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	format_check(char format, va_list args, int *count, int *error)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int), count, error);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), count, error);
	else if (format == 'p')
		ft_putptr(va_arg(args, void *), count, error);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), count, error);
	else if (format == 'u')
		ft_putnbr(va_arg(args, unsigned int), count, error);
	else if (format == 'x')
		ft_putnbr_hex(va_arg(args, unsigned int), 0, count, error);
	else if (format == 'X')
		ft_putnbr_hex(va_arg(args, unsigned int), 1, count, error);
	else if (format == '%')
		ft_putchar('%', count, error);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		error;

	error = 0;
	count = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format && error != -1)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				format_check(*format, args, &count, &error);
		}
		else
			ft_putchar(*format, &count, &error);
		format++;
	}
	va_end(args);
	if (error == -1)
		return (-1);
	return (count);
}
