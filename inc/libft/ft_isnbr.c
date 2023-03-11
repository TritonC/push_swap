/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:35:03 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/02/15 12:37:56 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnbr(char *nptr)
{
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	if (!*nptr)
		return (0);
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			return (0);
		nptr++;
	}
	return (1);
}
