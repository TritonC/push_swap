/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:19:59 by manuel            #+#    #+#             */
/*   Updated: 2023/03/11 10:53:14 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>


void	*ft_calloc(size_t n, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin(char const *dest, const char *src);
char	*get_next_line(int fd);
char	*check_line(char *str);
char	*rest_of_file(char *buffer);
char	*read_and_save(int fd, char *buff);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif