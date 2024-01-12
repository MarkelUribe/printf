/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:03:15 by muribe-l          #+#    #+#             */
/*   Updated: 2024/01/12 15:13:32 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"

int		ft_printf(char const *format, ...);
int		ft_hex(long nbr, int i, char *base);
int		get_conversion(char c, va_list args);
int		print_double(double d);