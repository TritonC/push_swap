/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <lgomes-o@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:08:39 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/06/27 19:06:16 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (s != NULL)
	{
		str = (char *) ft_calloc(ft_strlen(s) + 1, sizeof(char));
		if (str == NULL)
			return (NULL);
		i = 0;
		while (*(s + i) != '\0')
		{
			*(str + i) = f(i, (char)*(s + i));
			i++;
		}
		return (str);
	}
	return (NULL);
}
