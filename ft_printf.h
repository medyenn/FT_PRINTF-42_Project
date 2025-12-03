/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennih <mennih@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:02:40 by mennih            #+#    #+#             */
/*   Updated: 2025/11/20 11:37:23 by mennih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	print_char(int n, int *countptr);
void	print_str(char *str, int *countptr);
void	print_decimal(int nbr, int *countptr);
void	print_unsigned(unsigned int u, int *countptr);
void	print_adress(void *ptr, int *countptr);
void	print_uphexa(unsigned int x, int *countptr);
void	print_lowhexa(unsigned int x, int *countptr);

#endif
