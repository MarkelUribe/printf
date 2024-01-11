/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:13:18 by muribe-l          #+#    #+#             */
/*   Updated: 2024/01/11 19:55:44 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	*get_conversion(char c, va_list args)
{
	if (c == 'c')
		return (write(1, va_arg(args, char), 1));
	else if (c == 's')
		return
}

int	ft_printf(char const *format, ...)
{
	va_list args;
	va_start(args,format);
	va_arg(args,int )
	
	
	
	
	
	
	
	
	
	
	va_end(args);

}
