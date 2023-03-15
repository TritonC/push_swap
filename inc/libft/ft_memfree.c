/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:10:25 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/15 08:16:16 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_memfree(void **double_pointer, void *simple_str)
{
    int i;

    if (double_pointer)
    {
        i = 0;
        while (double_pointer[i])
        {
            free(double_pointer[i]);
            i++;
        }
        free(double_pointer);
    }
    if(simple_str)
        free (simple_str);
}