/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:56:09 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/25 12:04:45 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c);
int	ft_is_type(char c);

int	ft_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	long int nbr;
	long int res;

	res = 0;
	nbr = n;
	if (nbr < 0)
	{
		res += ft_putchar('-');
		nbr = nbr * (-1);
	}
	if (nbr > 9)
	{
		res += ft_putnbr(nbr / 10);
		res += ft_putnbr(nbr % 10);
	}
	else
	{
		res += ft_putchar(nbr + '0');
	}
	return (res);
}
