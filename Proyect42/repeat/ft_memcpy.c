/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:15:27 by alvdelga          #+#    #+#             */
/*   Updated: 2024/03/20 16:03:56 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;
	size_t				i;

	s = ((unsigned char *)src);
	d = ((unsigned char *)dst);
	i = 0;
	while (dst == src || !n)
		return (dst);
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
