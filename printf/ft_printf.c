/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaiz <mbaiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:35:14 by mbaiz             #+#    #+#             */
/*   Updated: 2024/03/05 09:52:26 by mbaiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printform(char sp, va_list ptr, int *counter)
{
	if (sp == 'c')
		ft_putchar(va_arg(ptr, int), counter);
	else if (sp == 's')
		ft_putstr(va_arg(ptr, char *), counter);
	else if (sp == '%')
		ft_putchar('%', counter);
	else if (sp == 'p')
		ft_putadr(va_arg(ptr, void *), counter);
	else if (sp == 'i' || sp == 'd')
		ft_putnbr(va_arg(ptr, int), counter);
	else if (sp == 'u')
		ft_putnbr_uns(va_arg(ptr, unsigned int), counter);
	else if (sp == 'x' || sp == 'X')
		ft_putnbr_hexa(va_arg(ptr, unsigned int), sp, counter);
	else
		ft_putchar(sp, counter);
}

int	ft_printf(const char *form, ...)
{
	int				i;
	int				counter;
	va_list			ptr;

	i = 0;
	counter = 0;
	if (write(1, &counter, 0) == -1)
		return (-1);
	va_start(ptr, form);
	while (form[i])
	{
		if (form[i] == '%' && form[i + 1])
		{
			i++;
			ft_printform(form[i], ptr, &counter);
		}
		else if (form[i] != '%')
			ft_putchar(form[i], &counter);
		i++;
	}
	va_end(ptr);
	return (counter);
}
