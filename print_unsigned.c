/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennih <mennih@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:18:39 by mennih            #+#    #+#             */
/*   Updated: 2025/11/20 09:12:17 by mennih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned(unsigned int u, int *countptr)
{
	char	c;

	if (u > 9)
		print_unsigned(u / 10, countptr);
	c = u % 10 + '0';
	(*countptr) += write(1, &c, 1);
}
