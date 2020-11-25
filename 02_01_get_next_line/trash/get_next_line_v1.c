/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 09:33:57 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/12 10:39:30 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_check_rest(char *rest, char **line)
{
	char	*ptr_rest;

	ptr_rest = NULL;
	if (rest)
	{
		if ((ptr_rest = ft_strchr(rest, '\n')))
		{
			*ptr_rest = '\0';
			*line = ft_strdup(rest);
			ft_strcpy(rest, ++ptr_rest);
		}
		else
		{
			*line = ft_strdup(rest);
			ft_strclr(rest);
		}
	}
	else
		*line = ft_strnew(1); 
	return (ptr_rest);
}

int	get_next_line(int fd, char **line)
{
	static	char	*rest;
	char			*ptr_rest;
	char			*tmp;
	char			buf[BUFFER_SIZE + 1];
	int				ret;

	ptr_rest = ft_check_rest(rest, line);
	while (!ptr_rest && (ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		if ((ptr_rest = ft_strchr(buf, '\n')))
		{
			*ptr_rest++ = '\0';
			rest = ft_strdup(ptr_rest);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return ((ret || ft_strlen(*line)) ? 1 : 0);
}

// int	main()
// {
// 	char	*line;
// 	int		fd;

// 	fd = open("test.txt", O_RDONLY);
// 	while (get_next_line(fd, &line))
// 	{
// 		printf("all is ok - %s\n", line);
// 	}
// 	return (0);
// }