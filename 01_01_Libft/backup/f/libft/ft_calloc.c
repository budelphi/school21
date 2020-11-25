/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:47:22 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/03 12:47:27 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*addr;
	size_t	nbytes;
	size_t	i;

	i = 0;
	nbytes = count * size;
	if (!(addr = malloc(nbytes)))
		return (NULL);
	while (nbytes--)
	{
		addr[i] = 0;
		i++;
	}
	return ((void *)addr);
}
