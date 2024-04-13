/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaiz <mbaiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:49:11 by mbaiz             #+#    #+#             */
/*   Updated: 2024/03/07 11:48:05 by mbaiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long int n, int *counter)
{
	char	a;

	if (n < 0)
	{
		ft_putchar('-', counter);
		n = -n;
	}
	if (n < 10)
	{
		a = n + '0';
		ft_putchar(a, counter);
	}
	else
	{
		ft_putnbr(n / 10, counter);
		ft_putnbr(n % 10, counter);
	}
}

void	ft_putnbr_uns(unsigned int nbr, int *counter)
{
	if (nbr < 10)
		ft_putchar(nbr + '0', counter);
	else
	{
		ft_putnbr_uns(nbr / 10, counter);
		ft_putnbr_uns(nbr % 10, counter);
	}
}

void	ft_putnbr_hexa(unsigned int nbr, char sp, int *counter)
{
	char	*base;

	if (sp == 'x')
		base = "0123456789abcdef";
	if (sp == 'X')
		base = "0123456789ABCDEF";
	if (nbr < 16)
		ft_putchar(base[nbr], counter);
	if (nbr >= 16)
	{
		ft_putnbr_hexa(nbr / 16, sp, counter);
		ft_putnbr_hexa(nbr % 16, sp, counter);
	}
}
