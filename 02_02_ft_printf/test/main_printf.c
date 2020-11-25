/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:44:20 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/23 10:51:27 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stidio.h>
#include "ft_printf.h"

void	f_a(int count, ...)
{
	int		value;
	int		i;
	va_list	vl;

	va_start(vl, count); // Устанавливает первый элемент 
	value = 0;
	i = 0;
	while (i < count)
	{
		value = va_arg(vl, int);
		printf("%i\n", value);
		i++;
	}
	va_end(vl); // Чистит 
	printf("\n");
}

int	main(void)
{
	f_a(5, 1, 2, 3, 4, 5);

	return (0);
}

int	main()
{
	int	ret;

	ret = ft_printf("format string\n");
	ret = printf("ret = %d\n", ret);
	printf("ret2 = %d", ret);
}