/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddresse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaiz <mbaiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:34:35 by mbaiz             #+#    #+#             */
/*   Updated: 2024/03/04 14:04:24 by mbaiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbradr(unsigned long long nbr, int *counter)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 16)
		ft_putchar(base[nbr], counter);
	else
	{
		ft_putnbradr(nbr / 16, counter);
		ft_putnbradr(nbr % 16, counter);
	}
}

void	ft_putadr(void *nbr, int *counter)
{
	unsigned long long	n;

	n = (unsigned long long)nbr;
	ft_putstr("0x", counter);
	ft_putnbradr(n, counter);
}
