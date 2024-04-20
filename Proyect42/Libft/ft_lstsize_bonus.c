/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:31:18 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/20 12:12:37 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*int	main(void)
{
	t_list	node1;
	t_list	node2;
	t_list	node3;
	t_list	node5;
	int		size;

	node1.content = "Nodo 1";
	node1.next = &node2;

	node2.content = "Nodo 2";
	node2.next = &node3;

	node3.content = "Nodo 3";
	node3.next = &node5;

	node5.content = "42";
	node5.next = NULL;

	// Pasa el puntero al primer nodo a ft_lstsize para contar los elementos
	size = ft_lstsize(&node1);

	printf("El tamaño de la lista es: %d\n", size);

	return (0);
}*/
