/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:15:05 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/10 12:07:39 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

// read - возвращает кол-во прочитанных байт 

char	*check_reaminder(char *reaminder, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (reaminder)
	{
		if ((p_n = ft_strchr(reaminder, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(reaminder);
			ft_strcpy(reaminder, ++p_n);
		}
		else
		{
			*line = ft_strdup(reaminder);
			ft_strclr(reaminder);
		}
	}
	else
		*line = ft_strnew(1); 
	return (p_n);
}


int	get_next_line(int fd, char **line)
{
	static	char	*reaminder;
	char			*p_n;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	int				byte_was_read;

	p_n = check_reaminder(reaminder, line);
	while (!p_n && (byte_was_read = read(fd, buf, BUFF_SIZE)))
	{
		buf[byte_was_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n++ = '\0';
			reaminder = ft_strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return (bite_was_read || ft_strlen(*line)) ? 1 : 0;
}

int	main(void)
{
	char	*line;
	int	fd;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd, &line);
	return (0);
}