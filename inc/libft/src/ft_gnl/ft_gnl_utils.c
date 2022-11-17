/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:39:28 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/07/16 13:52:37 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnlstrlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_gnlstrchr(char *str, int c)
{
	size_t	i;

	if (!str)
		return (NULL);
	if (c == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_gnljoin(char *s1, char *s2)
{
	char	*str;
	size_t	t_len;
	size_t	i;
	size_t	j;

	t_len = ft_gnlstrlen(s1) + ft_gnlstrlen(s2);
	str = (char *) malloc((t_len + 1) * sizeof(char));
	if (!s1 || !s2 || !str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[t_len] = '\0';
	free(s1);
	return (str);
}
