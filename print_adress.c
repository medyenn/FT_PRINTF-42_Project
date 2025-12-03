/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennih <mennih@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:17:53 by mennih            #+#    #+#             */
/*   Updated: 2025/11/20 10:57:47 by mennih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_adress(unsigned long long adress, int *countptr)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (adress > 15)
		ft_adress(adress / 16, countptr);
	(*countptr) += write(1, &hex[adress % 16], 1);
}

void	print_adress(void *ptr, int *countptr)
{
	unsigned long long	adress;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		(*countptr) += 5;
		return ;
	}
	adress = (unsigned long long)ptr;
	(*countptr) += write(1, "0x", 2);
	ft_adress(adress, countptr);
}
