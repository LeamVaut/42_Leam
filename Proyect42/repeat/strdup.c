/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:08:37 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/17 15:16:30 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strdup(const char *s1)
{
	char *s2;
	char lens1;

	lens1 = strlen(s1);

	s2 = malloc((lens1 * sizeof(char)) + 1);
	if (!s2)
		return (NULL);
	while (*s1)
	{
		*s2++ = *s1++; 
	}
	return (s2 - lens1);
}
int main() {
    const char *original = "Hola, mundo!";
    char *duplicado = strdup(original);

    printf("Cadena duplicada: %s\n", duplicado);

    return 0;
}



#include "stdio.h"
#include <string.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*d;
	char	*p_s1;
	size_t	i;

	p_s1 = (char *)s1;
	i = 0;
	d = (char *)malloc(ft_strlen(p_s1) + 1);
	if (d == NULL)
		return (NULL);
	while (p_s1[i] != '\0')
	{
		d[i] = p_s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
int main() {
    const char *original = "Hola, mundo!";
    char *duplicado = ft_strdup(original);

    printf("Cadena duplicada: %s\n", duplicado);

    return 0;
}
