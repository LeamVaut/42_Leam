/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:26:09 by alvdelga          #+#    #+#             */
/*   Updated: 2024/03/20 10:31:48 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int	numstring(char const *s1, char c)
{
	int	contp;
	int	flagM;

	contp = 0;
	flagM = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			flagM = 0;
		else if (flagM == 0)
		{
			flagM = 1;
			contp++;
		}
		s1++;
	}
	return (contp);
}

static int	numchar(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char	**freee(char const **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

static char	**dividir(char const *s, char **dst, char c, int l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[j] = (char *)malloc(sizeof(char) * numchar(s, c, i) + 1);
		if (dst[j] == NULL)
			return (freee((char const **)dst, j));
		while (s[i] != '\0' && s[i] != c)
			dst[j][k++] = s[i++];
		dst[j][k] = '\0';
		j++;
	}
	dst[j] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		l;

	if (s == NULL)
		return (NULL);
	l = numstring(s, c);
	dst = (char **)malloc(sizeof(char *) * (l + 1));
	if (dst == NULL)
		return (NULL);
	return (dividir(s, dst, c, l));
}
