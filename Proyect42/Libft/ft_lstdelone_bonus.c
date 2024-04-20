/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:31:45 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/20 14:00:50 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Toma como parámetro un nodo ’lst’ y libera la memoria del contenido
//utilizando la función ’del’ dada como parámetro, además
//de liberar el nodo. La memoria de ’next’ no debe liberarse.
/*static void	ft_del_node_content(void *content)
{
	if (content != NULL)
		free(content);
}*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL && del != NULL)
	{
		del(lst->content);
		free(lst);
	}
}
/*int main()
{
    // Creamos un nodo de lista y asignamos contenido
    t_list *node = (t_list *)malloc(sizeof(t_list));
    node->content = malloc(sizeof(int));
    *(int *)(node->content) = 42;
    node->next = NULL;

    // Imprimimos el contenido antes de eliminarlo
    printf("Contenido antes de eliminar: %d\n", *(int *)node->content);

    // Eliminamos el contenido del nodo
    ft_del_node_content(node->content);

    // Eliminamos el nodo
    ft_lstdelone(node, NULL);
	printf("Nodo eliminado correctamente\n");
    return 0;
}*/
