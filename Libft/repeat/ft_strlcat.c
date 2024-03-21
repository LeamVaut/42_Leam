/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:08:44 by alvdelga          #+#    #+#             */
/*   Updated: 2024/03/21 11:39:10 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
#include "string.h"

size_t ft_strlen(const char *str) {
    size_t len = 0;
    while (*str++) {
        len++;
    }
    return len;
}

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t londst;
	size_t lonsrc;
	size_t cont;

	londst = ft_strlen(dst);
	lonsrc = ft_strlen(src);

	if (dstsize <= londst)
		return (londst + dstsize);
	cont = londst;
	while (*src != '\0' && cont < (dstsize -1))
		*(dst + cont++) = *src++;
	*(dst + cont++) = '\0'; 
	return (londst + lonsrc);

}
int main() {
    char dst[20] = "Hello";
    char src[] = ", World!";

    // Concatenar src al final de dst
    size_t resultado = ft_strlcat(dst, src, sizeof(dst));

    printf("Cadena concatenada: %s\n", dst);
    printf("Longitud total: %zu\n", resultado);

    return 0;
}
