/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:44:47 by muribe-l          #+#    #+#             */
/*   Updated: 2024/01/12 10:45:16 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

int	print_double(double d)
{
	long	i;
	double	dec;
	int		length;

	i = d;
	dec = d - i;
	length = ft_strlen(ft_itoa(i));
	ft_putnbr_fd(i, 1);
	length += write(1, '.', 1);
	dec *= 100;
	ft_putnbr_fd((long)(dec + 0.5), 1);
	return (length + 2);
}

int	ft_hex(long nbr, int i, char *base)
{
	if (nbr == 0 || i == 0)
		return (write(1, '0', 1));
	if (nbr > 0)
	{
		i = ft_hex(nbr / 16, i++, base);
		write(1, &base[nbr % 16], 1);
	}
	return (i);
}