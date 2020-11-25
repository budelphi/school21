/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:23:48 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/11 13:57:49 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#define BUFF_SIZE 10

typedef struct		s_gnl
{
	int				fd;
	char			*rest;
	struct s_gnl	*next;
}					s_gnl;

// 10 функций

s_gnl		*ft_new_list(const int fd);
char		*ft_check_rest(char **ptr_rest, char *rest);
int			get_line(const int fd, char **line, char *rest);
int			get_next_line(const int fd, char **line);

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_str_chr_new(const char *str, int ch, size_t size);
char	*ft_str_cat_cpy(char *restrict str1, const char *restrict str2, char *dst, const char *src);
void	ft_clr_del(char *str, char **ptr_as);

//char	*ft_strcat(char *restrict str1, const char *restrict str2);
//char	*ft_strcpy(char *dst, const char *src);

//void	ft_strclr(char *s);
//void	ft_strdel(char **as);

// char	*ft_strchr(const char *str, int ch);
// char	*ft_strnew(size_t size);

#endif