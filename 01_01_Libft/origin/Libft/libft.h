/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:39:06 by budelphi          #+#    #+#             */
/*   Updated: 2020/11/06 16:41:45 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int ch);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_memcmp(const void *src, const void *dest, size_t count);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_tolower(int ch);
int					ft_toupper(int ch);
char				*ft_strchr(const char *str, int ch);
char				*ft_strdup(const char *str);
char				*ft_strrchr(const char *str, int ch);
char				*ft_strnstr(const char *str2, const char *str1, size_t len);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memccpy(void *dest, const void *src,
									int ch, size_t count);
void				*ft_memchr(const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t count);
void				*ft_memmove(void *restrict dest,
									const void *restrict src, size_t count);
void				*ft_memset(void *dest, int ch, size_t count);
void				ft_bzero(void *dest, size_t count);
size_t				ft_strlcat(char *restrict dest,
									const char *restrict src, size_t size);
size_t				ft_strlcpy(char *restrict dest,
									const char *restrict src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s, char const *set);
char				**ft_split(const char *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int n);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
									void (*del)(void *));

#endif
