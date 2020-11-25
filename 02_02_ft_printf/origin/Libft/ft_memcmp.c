/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:36:06 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/02 11:22:34 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	size_t			i;
	unsigned char	*ptr_buf1;
	unsigned char	*ptr_buf2;

	i = 0;
	ptr_buf1 = (unsigned char *)buf1;
	ptr_buf2 = (unsigned char *)buf2;
	if (count == 0)
		return (0);
	while (i < (count - 1) && ptr_buf1[i] == ptr_buf2[i])
		i++;
	return ((int)(ptr_buf1[i] - ptr_buf2[i]));
}
