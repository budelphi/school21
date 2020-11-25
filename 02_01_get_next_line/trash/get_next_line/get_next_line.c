/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:33:20 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/11 13:53:52 by budelphi         ###   ########.fr       */
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

	// Проверяю - выделилась ли у меня память под новый элемент 
	if (!(new_elem = (s_gnl *)malloc(sizeof(s_gnl))))
		return (NULL);
	
	// Начинаю работать с полями структуры 
	// В fd кладу fd, который пришел для обработки 
	new_elem->fd = fd;

	// rest - остаток после предыдущего считывания (если есть)
	// ft_str_chr_new - в данном случае работает как calloc
	// Выделяет память равную BUFF_SIZE и 'протыкивает ее нулями', чтобы там не оставалось мусора
	new_elem->rest = ft_str_chr_new(NULL, (int)NULL, BUFF_SIZE);
	
	// Ссылку на след.эл оставляю пустой 
	new_elem->next = NULL;

	// Возвращаю новый элемент 
	return (new_elem);
}

// Здесь идет проверка - осталось ли что-то от нашего предыдущего копирования
char		*ft_check_rest(char **ptr_rest, char *rest)
{
	char *str;

	// Если в остатке от предыдущего считывания есть символ начала строки 
	// То 
	// Здесь функция ft_str_chr_new - возвращает позицию элемента '\n' если он есть в строке 
	if ((*ptr_rest = ft_str_chr_new(rest, '\n', 0)))
	{
		// Возвращает подстроку из строки 'rest'. Подстрока начинается с индекса '0' и размером 'ptr_rest - rest'.
		str = ft_substr(rest, 0, *ptr_rest - rest);
		// Дальше просто идет копирование из
		ft_str_cat_cpy(NULL, NULL, rest, ++(*ptr_rest));
	}
	else
	{
		str = ft_str_chr_new(NULL, (int)NULL, (ft_strlen(rest) + 1));
		ft_str_cat_cpy(str, rest, NULL, NULL);
		ft_clr_del(rest, NULL);
	}
	return (str);
}


int			get_line(const int fd, char **line, char *rest)
{
	char			buf[BUFF_SIZE + 1];
	char			*ptr_rest;
	char			*tmp;
	int				rd;

	// ptr_rest - указатель на остаток от считывания 
	ptr_rest = NULL;
	
	// rd - кол-во считанных данных 
	rd = 1;

	// Здесь идет проверка - осталось ли что-то от нашего предыдущего копирования
	// Если осталось - добавляет это к строке, в которой должна лежать новая строка
	// Иначе - 
	*line = ft_check_rest(&ptr_rest, rest);
	while ((!ptr_rest) && (rd = read(fd, buf, BUFF_SIZE)))
	{
		buf[rd] = '\0';
		if ((ptr_rest = ft_str_chr_new(buf, '\n', 0)))
		{
			// Копирует в 'остаток' то, что не влезло в первую строку 
			ft_str_cat_cpy(NULL, NULL, rest, ++ptr_rest);
			// Отсекает то, что не влезо в первую строку 
			ft_clr_del(--ptr_rest, NULL);
		}
		tmp = *line;
		// Если не удалось соединить то, что уже было в линии и то, что считалось в буфер
		// Или rd < 0 
		if (!(*line = ft_strjoin(tmp, buf)) || rd < 0)
			return (-1);
		// чистит указатель tmp
		ft_clr_del(NULL, &tmp);
	}
	// Если нам удалось что-то положить в строку или в остаток или rd больше 0 - вернуть 1 
	// Иначе 0 
	return ((ft_strlen(*line) || ft_strlen(rest) || rd) ? 1 : 0);
}


int			get_next_line(const int fd, char **line)
{
	static s_gnl	*begin_list;
	s_gnl			*tmp;
	int				ret;

	// Проверяю корректный ли мне пришел дескриптор и ссылка на линию 
	if (fd < 0 || line == 0)
		return (-1);

	// Проверяю, создан ли хоть 1 элемент для работы с файлами 
	// если не создано ни одного элемента списка, отправляю дескриптор и создаю новый элемент
	// иначе просто продолжаю работать 
	if (!begin_list)
		begin_list = ft_new_list(fd);

	// Создаю временную переменную, чтобы не потерять начало списка
	tmp = begin_list;

	// Дальше прохожу по структуре и проверяю есть ли уже элемент с данным дескриптором
	// Если он есть, останавливаюсь на нем и начинаю с ним работать 
	// Иначе добавляю новый элемент с новым дескриптором 
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = ft_new_list(fd);
		tmp = tmp->next;
	}
	// ret - возвращаемое значение 
	// Отправляю дескпритор, строку и текущий остаток буфера от работы с данным fd 
	ret = get_line(fd, line, tmp->rest);

	// Возвращаю ret
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