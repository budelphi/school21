/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:10:09 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/25 11:15:17 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	printf("/***********************************/ \n");
	printf("/************** flags **************/ \n");
	printf("/***********************************/ \n");
	printf("\n");
	
	printf("0 flags with d:      |%0d|\n", 123);
	printf("06 flags with d:     |%06d|\n", 123);
	printf("-060 flags with d:   |%060d|\n", 123);
	printf("0*-6 flags with d:   |%0*d|\n", -6, 123);
	printf("-06.6 flags with d:  |%06.6d|\n", 123);
	printf("-0*6.6 flags with d: |%0*.6d|\n", 6, 123);

	printf("\n");
	printf("*-6 flags with d:   |%0*d|\n", -6, 123);


	printf("\n");
	printf("flags:\n");
	printf("1. 0 Дополняет нулями поле ширины, которое задается не через точку\n");
	printf("2. - Никак не влияет на 0\n");
	printf("3. - Нельзя использовать с 0\n");
	printf("\n");

	printf("/***********************************/ \n");
	printf("/************** width **************/ \n");
	printf("/***********************************/ \n");
	printf("\n");

	printf("6 width with d:  |%6d|\n", 123);
	printf("* width with d:  |%*d|\n", 6, 123);
	printf("-6 width with d: |%-6d|\n", 123);
	printf("-* width with d: |%-*d|\n", 6, 123);

	printf("\n");
	printf("width:\n");
	printf("1. Без 0 Дополняет пробелами поле ширины, которое задается не через точку\n");
	printf("2. -  Выравнивает влево 0\n");
	printf("\n");

	printf("/***********************************/ \n");
	printf("/************ precision ************/ \n");
	printf("/***********************************/ \n");
	printf("\n");

	printf("Особый случай:\n");
	//printf("%.0d - 1 width with d: |%.0d|\n", 0);
	//printf("%.0d - 1 width with d: |%.0d|\n", 1);

	return (0);
}