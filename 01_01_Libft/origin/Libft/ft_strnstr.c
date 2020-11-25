/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:51:53 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/02 11:38:09 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (*str2 == '\0')
		return ((char*)str1);
	while (str1[i] != '\0')
	{
		j = 0;
		while ((str1[i + j] == str2[j])
				&& (i + j < len))
		{
			j++;
			if (str2[j] == '\0')
				return ((char*)str1 + i);
		}
		i++;
	}
	if (str1[i] == str2[0] && i < len)
		return ((char*)str1 + i);
	return (NULL);
}
