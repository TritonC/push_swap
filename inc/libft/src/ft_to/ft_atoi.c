/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <lgomes-o@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:47:33 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/07/01 20:38:55 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long int		r;
	long long int		s;
	size_t				i;

	i = 0;
	if (*(str + i) == '\0')
		return (0);
	while ((*(str + i) >= 9 && *(str + i) <= 13) || *(str + i) == 32)
		i++;
	s = 1;
	if (*(str + i) == 45)
			s *= -1;
	if (*(str + i) == 45 || *(str + i) == 43)
		i++;
	r = 0;
	while (*(str + i) >= 48 && *(str + i) <= 57)
	{
		r = ((r * 10) + (*(str + i) - 48) * s);
		i++;
		if (r < -2147483648)
			return (0);
		if (r > 2147483647)
			return (-1);
	}
	return (r);
}
