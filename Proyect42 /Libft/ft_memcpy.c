/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:23:06 by alvdelga          #+#    #+#             */
/*   Updated: 2024/03/12 14:08:48 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;
	size_t				i;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	i = 0;
	while (dst == src || !n)
	{
		return (dst);
	}
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
/*int main() {
    // Arreglo de origen
    int src[] = {1, 2, 3, 4, 5};
    // Arreglo de destino
    int dst[5];

    // Copia del arreglo de origen al de destino usando ft_memcpy
    ft_memcpy(dst, src, sizeof(src));

    // Impresión del arreglo de destino
    printf("Arreglo de destino:\n");
    for (size_t i = 0; i < 5; i++) {
        printf("%d ", dst[i]);
    }
    printf("\n");

    return 0;
}*/
