/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:13:18 by muribe-l          #+#    #+#             */
/*   Updated: 2024/01/12 13:28:00 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	get_conversion2(char c, va_list args)
{
	int	p;

	if (c == 'i')
	{
		p = (int)va_arg(args, int);
		ft_putnbr_fd(p, 1);
		return ((int)ft_strlen(ft_itoa(p)));
	}
	else if (c == 'u')
	{
		p = (int)va_arg(args, unsigned int);
		ft_putnbr_fd(p, 1);
		return ((int)ft_strlen(ft_itoa(p)));
	}
	else if (c == 'x')
		return (ft_hex(va_arg(args, size_t), 0, "0123456789abcdef"));
	else if (c == 'X')
		return (ft_hex(va_arg(args, size_t), 0, "0123456789ABCDEF"));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
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
		ft_putstr_fd(p, 1);
		return (ft_strlen(p));
	}
	else if (c == 'p')
	{
		write (1, "0x", 2);
		return (ft_hex(va_arg(args, size_t), 0, "0123456789abcdef") + 2);
	}
	else if (c == 'd')
		return (print_double(va_arg(args, double)));
	else
		get_conversion2(c, args);
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (format)
	{
		if (*format == '%')
		{
			format++;
			len += (int)get_conversion(*format, args);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}