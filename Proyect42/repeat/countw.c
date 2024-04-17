/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:21:44 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/16 19:43:29 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	main(int argc, char *argv[])
{
	int i;
	int count;

	count = 0;
	i = 0;
	if (argc != 2)
		return (0);

	while (argv[1][i] && argv[1][i] == ' ')
		i++;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] != ' ' && argv[1][i])
			count++;
		while (argv[1][i] !=  ' ' && argv[1][i])
			i++;
		while (argv[1][i] == ' ' && argv[1][i])
			i++;
	}
	printf("%d", count);
	return (0);
}
