/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennih <mennih@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:18:14 by mennih            #+#    #+#             */
/*   Updated: 2025/11/20 09:10:21 by mennih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_decimal(int nbr, int *countptr)
{
	long	x;
	char	c;

	x = nbr;
	if (x < 0)
	{
		(*countptr) += write(1, "-", 1);
		x = -x;
	}
	if (x > 9)
		print_decimal(x / 10, countptr);
	c = (x % 10) + '0';
	(*countptr) += write(1, &c, 1);
}
