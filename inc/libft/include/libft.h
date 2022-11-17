/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <lgomes-o@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:55:05 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/07/01 01:15:54 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/* Linked List Struct */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* [Functions of libft] */
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_atoi(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_strnstr(const char *b, const char *s, size_t len);
char		*ft_strdup(const char *s);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(const char *s1, const char *set);
char		**ft_split(const char *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));

size_t		ft_strlcpy(char *d, char *s, size_t size);
size_t		ft_strlcat(char *d, char *s, size_t size);
size_t		ft_strlen(const char *str);

void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *str, int c, size_t n);
void		*ft_memmove(void *d, const void *s, size_t n);
void		*ft_memchr(void *s, int c, size_t n);
void		*ft_memcpy(void *d, const void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

/* [Linked List functions] */
int			ft_lstsize(t_list *lst);

t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));

#endif
