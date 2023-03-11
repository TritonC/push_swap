/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:46:55 by marvin            #+#    #+#             */
/*   Updated: 2023/02/15 12:31:40 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*dinamic_str(size_t size)
{
	char	*str;

	str = (char *)ft_calloc(sizeof(char) * (size + 1), 1);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		count;

	if (!s || !f)
		return (NULL);
	count = 0;
	str = dinamic_str(ft_strlen(s));
	if (!str)
		return (NULL);
	while (s[count])
	{
		str[count] = f(count, s[count]);
		count++;
	}
	return (str);
}
