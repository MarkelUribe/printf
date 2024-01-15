/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:13:18 by muribe-l          #+#    #+#             */
/*   Updated: 2024/01/15 16:55:21 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_conversion2(char c, va_list args)
{
	if (c == 'i' || c == 'd')
		return (ft_num((int)va_arg(args, int), 1) + 1);
	else if (c == 'u')
		return (ft_num(va_arg(args, unsigned int), 1) + 1);
	else if (c == 'x')
		return (ft_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else if (c == 'p')
	{
		write (1, "0x", 2);
		return (ft_hex_unisigned(va_arg(args, size_t), "0123456789abcdef") + 2);
	}
	return (0);
}

int	get_conversion(char c, va_list args)
{
	void	*p;

	if (c == 'c')
	{
		ft_putchar_fd((char)va_arg(args, int), 1);
		return (1);
	}
	else if (c == 's')
	{
		p = (char *)va_arg(args, char *);
		if (!p)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		ft_putstr_fd(p, 1);
		return (ft_strlen(p));
	}
	else
		return (get_conversion2(c, args));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len += (int)get_conversion(format[i], args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
