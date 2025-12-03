/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennih <mennih@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:01:08 by mennih            #+#    #+#             */
/*   Updated: 2025/11/20 11:33:43 by mennih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check(va_list args, const char *format, int *countptr)
{
	if (*format == 'd' || *format == 'i')
		print_decimal(va_arg(args, int), countptr);
	else if (*format == 'c')
		print_char(va_arg(args, int), countptr);
	else if (*format == 's')
		print_str(va_arg(args, char *), countptr);
	else if (*format == 'u')
		print_unsigned(va_arg(args, unsigned int), countptr);
	else if (*format == 'x')
		print_lowhexa(va_arg(args, unsigned int), countptr);
	else if (*format == 'X')
		print_uphexa(va_arg(args, unsigned int), countptr);
	else if (*format == 'p')
		print_adress(va_arg(args, void *), countptr);
	else if (*format == '%')
		(*countptr) += write(1, "%", 1);
	else
	{
		write(1, "%", 1);
		write(1, format, 1);
		*countptr += 2;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*(format) == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			ft_check(args, format, &count);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
