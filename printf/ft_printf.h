/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaiz <mbaiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:35:24 by mbaiz             #+#    #+#             */
/*   Updated: 2024/03/05 09:48:58 by mbaiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(char c, int *counter);
void	ft_putstr(char *str, int *counter);
void	ft_putnbr(long int nbr, int *counter);
void	ft_putnbr_uns(unsigned int nbr, int *counter);
void	ft_putnbr_hexa(unsigned int nbr, char sp, int *counter);
void	ft_putadr(void *nbr, int *counter);
int		ft_printf(const char *form, ...);

#endif