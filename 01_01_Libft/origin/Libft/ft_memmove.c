/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:30:40 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/19 12:58:39 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t			i;
	unsigned char	*dest2;
	unsigned char	*src2;

	dest2 = (unsigned char*)dest;
	src2 = (unsigned char*)src;
	i = 0;
	if (!src && !dest)
		return (NULL);
	if (src2 < dest2)
	{
		while (count-- > 0)
			dest2[count] = src2[count];
	}
	else
	{
		while (i < count)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	return (dest);
}
