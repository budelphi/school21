/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:13:08 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/07 16:40:15 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_is_digit(int c)
{
	return (c >= '0' && c <= '9');
}
static int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
	c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *str)
{
	int sign;
	unsigned long int result;

	sign = 1;
	result = 0;
	while (ft_is_whitespace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while ((*str != '\0') && ft_is_digit(*str))
	{
		result = (result * 10) + (*str - '0');
		if (result >= 9223372036854775807 && sign == 1)
			return (-1);
		else if (result > 9223372036854775807 && sign == -1)
			return (0);
		str++;
	}
	return ((int)(result * sign));
}


int	main()
{
	int	num1 = atoi("-9223372036854775808");
	int	num2 = atoi("9223372036854775807");
	int	num3 = atoi("-92233720368547759002");
	int	num4 = atoi("9223372036854775809");

	int	num5 = ft_atoi("-9223372036854775808");
	int	num6 = ft_atoi("9223372036854775807");
	int	num7 = ft_atoi("-92233720368547759002");
	int	num8 = ft_atoi("9223372036854775809");

	int	num9 = atoi("-4294967296");
	int	num10 = atoi("4294967296");
	int	num11 = ft_atoi("-4294967296");
	int	num12 = ft_atoi("4294967296");

	printf("atoi_min_long_long_int: %d\n", num1);
	printf("atoi_max_long_long_int: %d\n", num2);
	printf("atoi_mmn_long_long_int: %d\n", num3);
	printf("atoi_mmx_long_long_int: %d\n\n\n", num4);

	printf("ft_atoi_min_long_long_int: %d\n", num5);
	printf("ft_atoi_max_long_long_int: %d\n", num6);
	printf("ft_atoi_mmn_long_long_int: %d\n", num7);
	printf("ft_atoi_mmx_long_long_int: %d\n\n\n", num8);

	printf("atoi_min_long_long_int: %d\n", num9);
	printf("atoi_max_long_long_int: %d\n", num10);
	printf("ft_atoi_mmn_long_long_int: %d\n", num11);
	printf("ft_atoi_mmx_long_long_int: %d\n\n\n", num12);
}
