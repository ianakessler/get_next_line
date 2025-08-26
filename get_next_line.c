/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:56:04 by iaratang          #+#    #+#             */
/*   Updated: 2025/08/26 20:00:13 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
void	create_list(t_list **list, int	fd);
char	*get_line(t_list *list);
void	copy_str(t_list *list, char *str);
void	clear_list(t_list **list);

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line(list);
	return (next_line);
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
	int		str_len;

	if (!list)
		return (NULL);
	str_len = len_to_newline(list);
	new_line = malloc(str_len + 1);
	if (!new_line)
		return (NULL);
	copy_str(list, new_line);
	return (new_line);
}

void	copy_str(t_list *list, char *str)
{
	int	i;
	int	k;

	k = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return;
			}
			str[k++] = list->str[i++];
		}
		list = list->next;
	}
	str[k] = 0;
}

void	clear_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buffer == NULL || clean_node == NULL)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->str[i] != '\0' || last_node->str[i] != '\n')
		i++;
	while(last_node->str[i] != '\0' && last_node->str[++i] != '\0')
		buffer[k++] = last_node->str[i];
	buffer[k] = '\0';
	clean_node->str = buffer;
	clean_node->next = NULL;
	free_list(list, clean_node, buffer);
}


int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

}
