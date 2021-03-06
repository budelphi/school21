/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:07:25 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/25 12:30:36 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

typedef struct		s_list
{
	int				flags;
	int				width;
	int				precision;
	char			type;
}					t_printf;

/* Возвращаемое значение: отрицательное значение — признак ошибки; 				*/
/* в случае успеха функции возвращают кол-во записанных/выведенных байтов		*/
/* (без учёта нулевого байта в конце)											*/

/****************************************** FT_PRINTF ********************************************/
/* Возвращаемое значение: 																		 */
/* -- Отрицательное значение — ошибка;															 */
/* -- Кол-во записанных/выведенных байтов - в случае успеха; 									 */
/* (нулевой байт в конце не учитывается)													 	 */
/****************************************** FT_PRINTF ********************************************/

/****************************************** СТРУКТУРА ********************************************/
/* flags	 --
/* width	 --
/* precision --
/* type		 --
/****************************************** СТРУКТУРА ********************************************/

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_type(char c)
{
	if ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'))
		return (1);
	return (0);
}

int	ft_parse_struct(char **format, va_list *vl, t_printf *t_flags)
{
	ft_parse_flags(*format, &t_flags);
	ft_parse_width(*format, &t_flags);
	ft_parse_precision(*format, &t_flags);
	ft_parse_type(*format, &t_flags);
	return (0);

	while (!(ft_is_type(**format))
	{
		ft_parse_spec(&format, new_elem);
	}
	if (**format == 'd')
	{
		(*format)++;
		value = va_arg(*vl, int);
		ft_putnbr(value);
		return (1);
	}
}

/*************************************************************************************************/
/****************************************** ЗАКОНЧЕНО ********************************************/
/*************************************************************************************************/

int	ft_init_struct(t_printf *t_flags)
{
	t_flags->flags = 0;
	t_flags->width = 0;
	t_flags->precision = 0; 
	t_flags->type = '\0';
	return (0);
}

/*************************************************************************************************/
/****************************************** ЗАКОНЧЕНО ********************************************/
/*************************************************************************************************/

int	ft_treat_param(char **format, va_list *vl)
{
	t_printf	t_flags;
	int			res;

	res = 0;
	(*format)++;
	ft_init_struct(&t_flags);
	ft_parse_struct(format, vl, &t_flags);
	res += ft_print_param(&t_flags, vl);
	return (res);
}

/*************************************************************************************************/
/****************************************** ЗАКОНЧЕНО ********************************************/
/*************************************************************************************************/

int	ft_printf_body(char **format, va_list *vl, int res)
{
	while (**format != '\0')
	{
		if (**format != '%')
		{
			res += ft_putchar(**format);
			(*format)++;
		}
		else
			res += ft_treat_param(format, &vl);
		if (res == -1)
			return (res); 
	}
	return (res);
}

/*************************************************************************************************/
/****************************************** ЗАКОНЧЕНО ********************************************/
/*************************************************************************************************/

int	ft_printf(const char *format, ...)
{
	va_list	vl;
	int		res;

	if (!format)
		return (-1);
	res = 0;
	va_start(vl, format);
	res = ft_printf_body((char **)&format, &vl, res);
	va_end(vl);
	return (res);
}

/*************************************************************************************************/
/***************************************** ТЕСТИРОВАНИЕ ******************************************/
/*************************************************************************************************/

int	main(void)
{
	ft_printf("double is %d", 35);
	return (0);
}
