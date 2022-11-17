/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <lgomes-o@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:13:39 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/06/21 20:48:55 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tmp;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	tmp = (char *) malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (0);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(tmp + i) = *(s + i);
		i++;
	}
	*(tmp + i) = '\0';
	return (tmp);
}
