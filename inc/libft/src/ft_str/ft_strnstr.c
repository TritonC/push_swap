/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <lgomes-o@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:22:11 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/09/12 02:00:55 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *b, const char *s, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s == '\0')
		return ((char *)b);
	while (*(b + i) != '\0' && (i < len))
	{
		j = 0;
		if (*(b + i) == *(s + j))
		{
			while (*(b + (i + j)) == *(s + j) && i + j < len)
			{
				if (*(s + (j + 1)) == '\0')
					return (((char *)b + i));
				j++;
			}
		}
		i++;
	}
	return (0);
}
