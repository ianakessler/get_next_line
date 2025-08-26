/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next__line_utils..c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:37:20 by iaratang          #+#    #+#             */
/*   Updated: 2025/08/25 16:38:40 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(t_list **list)
{
	
}

t_list	*find_last_node(t_list **list)
{
	t_list *node;

	node = *list;
	while (node)
		node = node->next;
	return (node);
}

void	append(t_list **list, char *buffer)
{
	t_list	*last_node;
	t_list	*new_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str = buffer;
	new_node->next = NULL;

}
