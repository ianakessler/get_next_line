/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:56:04 by iaratang          #+#    #+#             */
/*   Updated: 2025/08/25 16:39:06 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	list = NULL;
}

void	create_list(t_list **list, int	fd)
{
	int		chars_read;
	char	*buff;

	while (!find_newline(*list))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (buff == NULL)
			return ;
		chars_read = read(fd, buff, BUFFER_SIZE);
		if (!chars_read)
		{
			free(buff);
			return ;
		}
		buff[chars_read] = '\0';
		append(list, buff);
	}
}


int	main(void)
{
	int	fd;
	char buffer[255];
	int	chars_read;

	fd = open("text.txt", O_RDONLY);

	while ((chars_read = read(fd, buffer, 25)))
	{
		buffer[chars_read] = '\0';
		printf("buf -> %s\n", buffer);
	}
	return (0);
}
