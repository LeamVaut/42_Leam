/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:10:31 by alvdelga          #+#    #+#             */
/*   Updated: 2024/03/21 17:25:15 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int flag;
	int ocurrencia;
	int i;

	flag = 0;
	ocurrencia = 0;
	i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
		{
			flag = 1;
			ocurrencia = i;
		}
		i++;
	}
	if (flag == 1)
		return ((char *)&str[ocurrencia]);
	if ((unsigned char)c == '\0')
	   return ((char *)&str[i]);
	return (NULL);	
}
