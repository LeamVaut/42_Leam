/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:15:19 by alvdelga          #+#    #+#             */
/*   Updated: 2024/03/21 12:59:14 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c && s[i] != '\0')
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c  == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
int main() {
    const char *cadena = "Hello, World!";
    int caracter_a_buscar = 'o';

    char *resultado = ft_strchr(cadena, caracter_a_buscar);
    if (resultado != NULL) {
        printf("El primer '%c' se encuentra en la posición: %ld\n", caracter_a_buscar, resultado - cadena);
    } else {
        printf("El caracter '%c' no se encuentra en la cadena.\n", caracter_a_buscar);
    }

    return 0;
}
