#include "get_next_line.h"


char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen((char *)src) + 1))))
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (size > 0)
		str[size--] = '\0';
	str[0] = '\0';
	return (str);
}

// char	*check_reaminder(char *reaminder, char **line)
// {
// 	char	*p_n;

// 	p_n = NULL;
// 	if (reaminder)
// 	{
// 		if ((p_n = ft_strchr(reaminder, '\n')))
// 		{
// 			*p_n = '\0';
// 			*line = ft_strdup(reaminder);
// 			ft_strcpy(reaminder, ++p_n);
// 		}
// 		else
// 		{
// 			*line = ft_strdup(reaminder);
// 			ft_strclr(reaminder);
// 		}
// 	}
// 	else
// 		*line = ft_strnew(1); 
// 	return (p_n);
// }

// 2
void	ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}

// 3
void	ft_strdel(char **as)
{
	if (as == 0)
		return ;
	if (*as)
		free(*as);
	*as = 0;
}

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
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

char	*ft_strcat(char *restrict str1, const char *restrict str2)
{
	char *tmp;

	tmp = str1;
	while (*str1)
		str1++;
	while (*str2)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (*s == c)
		return ((char*)s);
	else
		return (0);
}