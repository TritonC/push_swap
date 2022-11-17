/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <lgomes-o@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:27:24 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/06/19 14:33:59 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *d, char *s, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{	
		while (*(s + i) != '\0' && i < size - 1)
		{
			*(d + i) = *(s + i);
			i++;
		}
		*(d + i) = '\0';
	}
	return (ft_strlen(s));
}
