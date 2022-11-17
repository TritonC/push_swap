/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <lgomes-o@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:29:18 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/06/27 15:36:51 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	dest = (unsigned char *)d;
	src = (unsigned char *)s;
	i = 0;
	if (n > 0 && dest != src)
	{
		while (i < n)
		{
			*(dest + i) = *(src + i);
			i++;
		}
	}
	return (d);
}
