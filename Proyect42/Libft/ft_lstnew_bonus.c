/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:50:38 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/20 11:18:08 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Crea un nuevo nodo utilizando malloc(3). La variable miembro ’content’ se
//inicializa con el contenido del parámetro ’content’.
//La variable ’next’, con NULL.
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*int	main(void)
{
	// Prueba 1: Crear un nodo con contenido de tipo entero
	int *data = (int *)malloc(sizeof(int));
	*data = 42;
	t_list *node1 = ft_lstnew(data);

	// Prueba 2: Crear un nodo con contenido de tipo cadena de caracteres
	char *str = "Hello, World!";
	t_list *node3 = ft_lstnew(str);

	printf("Node 1 content: %d\n", *(int *)(node1->content));
	printf("Node 3 content: %s\n", (char *)(node3->content));

	free(data);
	free(node1);
	free(node3);

	return (0);
}*/
