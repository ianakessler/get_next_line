/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:56:03 by iaratang          #+#    #+#             */
/*   Updated: 2025/08/26 17:35:35 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

int	find_newline(t_list *list);
t_list	*find_last_node(t_list *list);
void	append(t_list **list, char *buffer);
void	create_list(t_list **list, int	fd);
int	len_to_newline(t_list *list);
void	print_nodes(t_list *list);


#endif
