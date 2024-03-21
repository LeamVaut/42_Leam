/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:03:14 by alvdelga          #+#    #+#             */
/*   Updated: 2024/03/18 21:07:05 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	longitud;
	int	flag;
	int	ocurrence;

	flag = 0;
	ocurrence = 0;
	longitud = 0;
	while (str[longitud])
	{
		if (str[longitud] == (unsigned char)c)
		{
			flag = 1;
			ocurrence = longitud;
		}
		longitud++;
	}
	if (flag == 1)
		return ((char *)&str[ocurrence]);
	if ((unsigned char)c == '\0')
		return ((char *)&str[longitud]);
	return (NULL);
}
