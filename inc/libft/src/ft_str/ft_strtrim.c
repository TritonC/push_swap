/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 00:29:44 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/06/28 03:01:40 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	if_exist(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	start = 0;
	while (*(s1 + start) != '\0' && if_exist(set, *(s1 + start)))
		start++;
	end = ft_strlen(s1);
	while (start < end && if_exist(set, *(s1 + (end - 1))))
		end--;
	str = (char *) ft_calloc((end - start) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (start < end)
	{
		*(str + i) = *(s1 + start);
		start++;
		i++;
	}
	return (str);
}	
