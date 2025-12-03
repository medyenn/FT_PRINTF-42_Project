/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uphexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennih <mennih@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:19:28 by mennih            #+#    #+#             */
/*   Updated: 2025/11/20 11:36:11 by mennih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_uphexa(unsigned int n, int *countptr)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (n > 15)
		print_uphexa(n / 16, countptr);
	(*countptr) += write(1, &hex[n % 16], 1);
}
