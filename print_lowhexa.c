/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lowhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennih <mennih@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:19:05 by mennih            #+#    #+#             */
/*   Updated: 2025/11/20 11:36:06 by mennih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_lowhexa(unsigned int n, int *countptr)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n > 15)
		print_lowhexa(n / 16, countptr);
	(*countptr) += write(1, &hex[n % 16], 1);
}
