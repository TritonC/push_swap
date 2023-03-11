/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:29:49 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/02/15 12:30:02 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *nptr)
{
	long long	result;
	int			sign;

	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	result = 0;
	while (ft_isdigit(*nptr))
	{
		result = (result * 10) + (*nptr - 48);
		nptr++;
	}
	return (sign * result);
}
