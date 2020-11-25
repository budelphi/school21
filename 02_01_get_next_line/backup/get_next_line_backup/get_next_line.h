/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:29:49 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/12 11:06:26 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#define BUFFER_SIZE 10
#define REST_SIZE 1024

int		get_next_line(const int fd, char **line);
// char	*ft_check_rest(char *rest, char **line);

char	*ft_strdup(const char *src);
char	*ft_strchr(const char *str, int ch);
char	*ft_strcpy(char *dst, const char *src);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

// char	*ft_strnew(size_t size);
// void	ft_strclr(char *s);
// void	ft_strdel(char **as);

#endif