/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:03:15 by muribe-l          #+#    #+#             */
/*   Updated: 2024/01/15 16:18:47 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"

int		ft_printf(char const *format, ...);
int		ft_hex_unisigned(unsigned long nbr, char *base);
int		ft_hex(long nbr, char *base);
int		get_conversion(char c, va_list args);
int		print_double(double d);
int		ft_num(long n, int fd);