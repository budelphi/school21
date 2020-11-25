/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:22:18 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/11 13:52:27 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_clr_del(char *str, char **ptr_as)
{
	if (str)
	{
		while (*str)
			*str++ = '\0';
	}
	if (ptr_as == 0)
		return ;
	if (*ptr_as)
		free(*ptr_as);
	*ptr_as = 0;
}

char	*ft_str_chr_new(const char *str, int ch, size_t size)
{
	size_t i;
	char *new_str;

	if (str && ch)
	{
		i = 0;
		while (str[i++] != '\0')
		{
			if (str[i] == ch)
				return ((char*)str + i);
		}
		if (str[i] == '\0' && ch == '\0')
			return ((char*)str + i);
	}
	else if (size)
	{
		new_str = (char *)malloc(sizeof(char) * (size + 1));
		if (new_str == NULL)
			return (NULL);
		while (size > 0)
			new_str[size--] = '\0';
		new_str[0] = '\0';
		return (new_str);
	}
	return (NULL);
}

char	*ft_str_cat_cpy(char *restrict str1, const char *restrict str2, char *dst, const char *src)
{
	char *tmp;
	int i;

	if (str1 && str2)
	{
		tmp = str1;
		while (*str1)
			str1++;
		while (*str2)
			*str1++ = *str2++;
		*str1 = '\0';
		return (tmp);
	}
	if (dst && src)
	{
		i = 0;
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*newstr;

	i = 0;
	j = 0;
	len = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(newstr = (char *)malloc(sizeof(*newstr) * (len + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substr;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (!(substr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (s_len < ((size_t)start))
	{
		substr[0] = '\0';
		return (substr);
	}
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
