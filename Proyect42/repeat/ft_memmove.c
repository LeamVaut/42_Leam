/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:12:51 by alvdelga          #+#    #+#             */
/*   Updated: 2024/03/20 16:01:53 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*p_dst;
	unsigned const char		*p_src;

	if (dst < src)
		return (ft_memcpy(dst, src, len));
	p_dst = (unsigned char *)dst;
	p_src = (unsigned const char *)src;
	if (dst == src || !len)
		return (dst);
	while (len--)
		p_dst[len] = p_src[len];
	return (dst);
}
/*int main() {
    char src[] = "Hello, world!";
    char dst[20];

    ft_memmove(dst, src, strlen(src) + 1);

    printf("dst después de ft_memmove: %s\n", dst);

    return 0;
}*/
