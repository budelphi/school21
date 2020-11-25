/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:11:48 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/25 10:16:53 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

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

int	main(void)
{
	printf("  |%d|\n", ft_putnbr(-35));
	printf("   |%d|\n", ft_putnbr(35));
	printf("    |%d|\n", ft_putnbr(0));
	printf("    |%d|\n", ft_putnbr(-0));

	return (0);
}