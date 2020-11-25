/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:35:38 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/25 12:11:48 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_init_struct(t_printf *t_flags)
{
	t_flags->flags = 0;
	t_flags->width = 0;
	t_flags->precision = 0; 
	t_flags->type = '\0';
	return (0);
}

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
