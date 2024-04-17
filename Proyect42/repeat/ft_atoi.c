/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:13:44 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/16 19:44:51 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	ft_atoi(const char *str)
{
	int i;
	int signo;
	int result;
	
	result = 0;
	signo = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		str++;
	if (str[i] == '-')
		signo = -1;
	if (str[i] == '-' || str[i] == '+')
		str++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		str++;
	}
	return (result * signo);
}
int	main()
{
	char *str = " \n-123";
	int result = ft_atoi(str);
	
	printf("%d\n", result);

	char a[] = "    \n\n\v\f\r\t -5234AAAgreghrsth";
	printf("%d\n",ft_atoi(a));

	return (0);
}
