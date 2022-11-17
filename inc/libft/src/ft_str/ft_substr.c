/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <lgomes-o@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:07:59 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/06/27 18:55:20 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	sub = (char *) ft_calloc(len + 1, sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	if (!(start > ft_strlen(s)))
	{
		while (i < len)
		{
			*(sub + i) = *(s + start);
			i++;
			start++;
		}
	}
	*(sub + i) = '\0';
	return (sub);
}
