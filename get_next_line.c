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

char	*get_next_line(int fd);
void	create_list(t_list **list, int	fd);

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line(list);
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

char	*get_line(t_list *list)
{
	char	*new_line;

	new_line = malloc(len_to_newline(list) + 1);
	if (!new_line)
		return (NULL);
	
}

char	*copy_str(t_list *list, char *line)
{

}


int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	get_next_line(fd);
}
