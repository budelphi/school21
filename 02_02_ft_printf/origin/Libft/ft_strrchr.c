/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:25:22 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/04 14:32:09 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*res;
	char	c;

	res = (char *)str + ft_strlen((char *)str);
	c = (char)ch;
	while (res >= str)
	{
		if (*res == c)
			return (res);
		res--;
	}
	return (NULL);
}
