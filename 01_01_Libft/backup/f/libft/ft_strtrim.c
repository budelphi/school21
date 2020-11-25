/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:07:26 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/04 16:21:30 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_set(char s, char const *set)
{
	int		flag;
	size_t	i;

	i = 0;
	flag = 0;
	while (set[i] != '\0')
	{
		if (s == set[i])
			flag = 1;
		i++;
	}
	return (flag);
}

char		*ft_strtrim(char const *s, char const *set)
{
	size_t	end_index;
	size_t	start_index;

	end_index = 0;
	start_index = 0;
	if (!s)
		return (NULL);
	end_index = ft_strlen(s);
	end_index = (end_index == 0) ? 0 : --end_index;
	while (ft_find_set(s[start_index], set) == 1 && start_index <= end_index)
		start_index++;
	while (ft_find_set(s[end_index], set) == 1 && end_index > start_index)
		end_index--;
	return (ft_substr(s, start_index, end_index - start_index + 1));
}
