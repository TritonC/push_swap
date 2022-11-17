/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <lgomes-o@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:30:37 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/06/20 17:47:32 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	dest = (unsigned char *)d;
	src = (unsigned char *)s;
	if (n > 0 && dest != src)
	{
		i = 0;
		if (dest > src)
		{
			while (++i <= n)
				*(dest +(n - i)) = *(src + (n - i));
		}
		else
		{
			while (i < n)
			{	
				*(dest + i) = *(src + i);
				i++;
			}
		}
	}
	return (d);
}
