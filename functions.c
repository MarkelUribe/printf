/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:44:47 by muribe-l          #+#    #+#             */
/*   Updated: 2024/01/15 16:18:48 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num(long n, int fd)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (10);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i = ft_num(-n, fd) + 1;
	}
	else if (n >= 10)
	{
		i = ft_num(n / 10, fd) + 1;
		ft_putchar_fd((n % 10) + '0', fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
	return (i);
}

int	ft_hex_unisigned(unsigned long nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr < 16)
	{
		write(1, &base[nbr % 16], 1);
		return (1);
	}
	if (nbr > 0)
	{
		i = ft_hex(nbr / 16, base);
		write(1, &base[nbr % 16], 1);
	}
	return (i + 1);
}

int	ft_hex(long nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr < 16)
	{
		write(1, &base[nbr % 16], 1);
		return (1);
	}
	if (nbr > 0)
	{
		i = ft_hex(nbr / 16, base);
		write(1, &base[nbr % 16], 1);
	}
	return (i + 1);
}
