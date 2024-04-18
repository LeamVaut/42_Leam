/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:03:44 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/18 19:50:42 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

static int numstring(char const *s1, char c)
{
	int flag;
	int string;
	int i;

	i = 0;
	string = 0;
	flag = 0;
	if (*s1 == '\0' || c == '\0')
		return (0);
	while (s1[i])
	{
		if (s1[i] == c)
		{
			flag = 0;
		}
		else if (flag == 0)
		{
			string++;
			flag = 1;
		}
		i++;
	}
	return (string);
}
static int countword(char const *s2, char c, int i)
{
	int leng;

	leng = 0;
	while (s2[i] != c && s2[i])
	{
		leng++;
		i++;
	}
	return (leng);

}
static char **freee (char const **dst, int j)
{
	while(j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

int main()
{
	char *string = "En un lugar de la mancha ";
	char c = ' ';
	int i = 6;

	int result = countword(string, c, i);
	printf ("El nummero de palabras en el string es: %d\n", result);
	return (0);
}
