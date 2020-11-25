/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:33:20 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/11 14:03:30 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Параметры:
// #1. Дескриптор файла для чтения
// #2. Значение того, что было прочитано

// Возвращаемое значение: 
// 1: Считана строка
// 0 : EOF достигнута
// -1: Произошла ошибка

// Описание 
// Записать функцию, которая возвращает строку, считанную с
// дескриптор файла, без новой строки.

// s_gnl - структура для работы с несколькими file descriptor

s_gnl		*ft_new_list(const int fd)
{
	s_gnl	*new_elem;

	if (!(new_elem = (s_gnl *)malloc(sizeof(s_gnl))))
		return (NULL);
	new_elem->fd = fd;
	//new_elem->rest = ft_strnew(BUFF_SIZE);
	new_elem->rest = ft_str_chr_new(NULL, (int)NULL, BUFF_SIZE);
	new_elem->next = NULL;
	return (new_elem);
}

// Если в остатке от предыдущего считывания лежит часть от предыдущей строки, я закидываю это в остаток
// Если там ничего нет, то я просто зануляю строку и чищу указатель на остаток, чтобы не было ликов   

char		*ft_check_rest(char **ptr_rest, char *rest)
{
	char *str;

	//if ((*ptr_rest = ft_strchr(rest, '\n')))
	if ((*ptr_rest = ft_str_chr_new(rest, '\n', 0)))
	{
		str = ft_substr(rest, 0, *ptr_rest - rest);
		//ft_strcpy(rest, ++(*ptr_rest));
		ft_str_cat_cpy(NULL, NULL, rest, ++(*ptr_rest));
	}
	else
	{
		//str = ft_strnew(ft_strlen(rest) + 1);
		str = ft_str_chr_new(NULL, (int)NULL, (ft_strlen(rest) + 1));
		//ft_strcat(str, rest);
		ft_str_cat_cpy(str, rest, NULL, NULL);
		ft_clr_del(rest, NULL);
	}
	return (str);
}

// rd - кол-во считанных байтов из файла 

int			get_line(const int fd, char **line, char *rest)
{
	char			buf[BUFF_SIZE + 1];
	char			*ptr_rest;
	char			*tmp;
	int				rd;

	ptr_rest = NULL;
	rd = 1;

	// Проверяю есть ли что-то в остатке
	*line = ft_check_rest(&ptr_rest, rest);
	while ((!ptr_rest) && (rd = read(fd, buf, BUFF_SIZE)))
	{
		buf[rd] = '\0';
		//if ((ptr_rest = ft_strchr(buf, '\n')))
		if ((ptr_rest = ft_str_chr_new(buf, '\n', 0)))
		{
			//ft_strcpy(rest, ++ptr_rest);
			ft_str_cat_cpy(NULL, NULL, rest, ++ptr_rest);
			ft_clr_del(--ptr_rest, NULL);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || rd < 0)
			return (-1);
		ft_clr_del(NULL, &tmp);
	}
	return ((ft_strlen(*line) || ft_strlen(rest) || rd) ? 1 : 0);
}

// ret - возвращаемое значение 

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

int		main(int argc, char **argv)
{
	char	*line;
	int		fd1;
	int		fd2;
	int		ret;

	if (argc == 3)
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
	}
	else if (argc == 2)
		fd2 = 0;
	else if (argc == 2)
	{
		fd1 = 0;
		fd2 = 0;
	}

	line = NULL;
	ret = 1;

	printf("\ntest1.txt:\n\n");

	while ((ret = get_next_line(fd1, &line)))
	{
		printf("%s\treturn value = %d\n", line, ret);
		ft_clr_del(NULL, &line);
	}

	printf("\ntest2.txt:\n\n");
	ret = 1;

	while ((ret = get_next_line(fd2, &line)))
	{
		printf("%s\treturn value = %d\n", line, ret);
		ft_clr_del(NULL, &line);
	}

	close(fd1);
	close(fd2);

	printf("\nclose fd\n\n");

	return (0);
}