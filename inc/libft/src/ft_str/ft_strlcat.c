/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <lgomes-o@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:36:41 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/09/12 03:23:37 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, char *s, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	res;

	len = ft_strlen(d);
	res = ft_strlen(d);
	i = 0;
	if (size > 0 && len < size)
	{
		while (*(s + i) && len < size - 1)
		{
			*(d + len) = *(s + i);
			len++;
			i++;
		}
		*(d + len) = '\0';
		res += ft_strlen(s);
	}
	else
		res = ft_strlen(s) + size;
	return (res);
}
