/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:56:03 by iaratang          #+#    #+#             */
/*   Updated: 2025/08/25 16:38:58 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

int	find_newline(char *s);


#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


#endif
