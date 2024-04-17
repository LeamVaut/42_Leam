/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:30:10 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/16 20:58:21 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = malloc(count * size);
	if (!result)
	{
		free(result);
		result = (void *) '\0';
		return (NULL);
	}
	else
	{
		ft_bzero(result, (count * size));
		return (result);
	}
}
int main()
{
    char array[5];
    ft_calloc(array, 5);

    int i = 0;

 	 while (i < sizeof(array))
 	 {
   		 printf("%s", array[i]);
   		 i++;
	  }
 	   return (0);
}
