/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:25:50 by alvdelga          #+#    #+#             */
/*   Updated: 2024/03/20 10:59:42 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	flag_verificar(char const *s1, char c)
{
	int	i;

	i = 0;
	while (s1 && s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*new;
	size_t	len;
	size_t	k;

	i = 0;
	k = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	while (flag_verificar(set, s1[i]) && s1[i])
		i++;
	while (len > 0 && flag_verificar(set, s1[len - 1]))
		len--;
	if (len < i)
		len = i;
	new = malloc(len - i + 1);
	if (!new)
		return (NULL);
	while (i < len)
		new[k++] = s1[i++];
	new[k] = '\0';
	return (new);
}
