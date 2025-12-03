/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennih <mennih@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:17:24 by mennih            #+#    #+#             */
/*   Updated: 2025/11/20 09:11:57 by mennih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(char *str, int *countptr)
{
	if (str == NULL)
	{
		(*countptr) += write(1, "(null)", 6);
		return ;
	}
	while (*str)
		(*countptr) += write(1, str++, 1);
}
