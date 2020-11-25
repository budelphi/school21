/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:33:20 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/11 14:15:16 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

s_gnl		*ft_new_list(const int fd)
{
	s_gnl	*new_elem;

	if (!(new_elem = (s_gnl *)malloc(sizeof(s_gnl))))
		return (NULL);
	new_elem->fd = fd;
	new_elem->rest = ft_strnew(BUFF_SIZE);
	new_elem->next = NULL;
	return (new_elem);
}

char		*ft_check_rest(char **ptr_rest, char *rest)
{
	char *str;

	if ((*ptr_rest = ft_strchr(rest, '\n')))
	{
		str = ft_substr(rest, 0, *ptr_rest - rest);
		ft_strcpy(rest, ++(*ptr_rest));
	}
	else
	{
		str = ft_strnew(ft_strlen(rest) + 1);
		ft_strcat(str, rest);
		ft_strclr(rest);
	}
	return (str);
}

int			get_line(const int fd, char **line, char *rest)
{
	char			buf[BUFF_SIZE + 1];
	char			*ptr_rest;
	char			*tmp;
	int				rd;

	ptr_rest = NULL;
	rd = 1;
	*line = ft_check_rest(&ptr_rest, rest);
	while ((!ptr_rest) && (rd = read(fd, buf, BUFF_SIZE)))
	{
		buf[rd] = '\0';
		if ((ptr_rest = ft_strchr(buf, '\n')))
		{
			ft_strcpy(rest, ++ptr_rest);
			ft_strclr(--ptr_rest);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || rd < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return ((ft_strlen(*line) || ft_strlen(rest) || rd) ? 1 : 0);
}

int			get_next_line(const int fd, char **line)
{
	static s_gnl	*begin_list;
	s_gnl			*tmp;
	int				ret;

	if (fd < 0 || line == 0)
		return (-1);
	if (!begin_list)
		begin_list = ft_new_list(fd);
	tmp = begin_list;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = ft_new_list(fd);
		tmp = tmp->next;
	}
	ret = get_line(fd, line, tmp->rest);
	return (ret);
}

int		main()
{
	char	*line;
	int		fd1;
	int		fd2;
	int		ret;


	fd1 = open("TEST.TXT", O_RDONLY);
	fd2 = open("TEST2.TXT", O_RDONLY);

	line = NULL;
	ret = 1;

	printf("\ntest1.txt:\n\n");

	while ((ret = get_next_line(fd1, &line)))
	{
		printf("%s\treturn value = %d\n", line, ret);
		ft_strdel(&line);
	}

	printf("\ntest2.txt:\n\n");
	ret = 1;

	while ((ret = get_next_line(fd2, &line)))
	{
		printf("%s\treturn value = %d\n", line, ret);
		ft_strdel(&line);
	}

	close(fd1);
	close(fd2);

	printf("\nclose fd\n\n");

	return (0);
}