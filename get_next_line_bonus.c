/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:56:04 by iaratang          #+#    #+#             */
/*   Updated: 2025/09/04 17:45:40 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char		*reset_bucket(char *bucket);
char		*create_new_line(char *bucket);
void		*free_all(char **buffer, char **bucket);
char		*fill_bucket(int fd, char *bucket, char *buffer);

char	*get_next_line(int fd)
{
	static char	*bucket[MAX_FD];
	char		*buffer;
	char		*temp;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (free_all(&bucket[fd], &buffer));
	if (!bucket[fd])
		bucket[fd] = ft_calloc(1, 1);
	bucket[fd] = fill_bucket(fd, bucket[fd], buffer);
	if (!bucket[fd])
		return (NULL);
	temp = create_new_line(bucket[fd]);
	bucket[fd] = reset_bucket(bucket[fd]);
	return (temp);
}

char	*fill_bucket(int fd, char *bucket, char *buffer)
{
	char	*temp;
	int		chars_read;

	chars_read = 1;
	while (!ft_strchr(bucket, '\n') && chars_read > 0)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read < 0)
		{
			free(buffer);
			free(bucket);
			return (NULL);
		}
		buffer[chars_read] = '\0';
		temp = ft_strdup(bucket);
		free(bucket);
		bucket = ft_strjoin(temp, buffer);
		free(temp);
	}
	free(buffer);
	return (bucket);
}

char	*reset_bucket(char *bucket)
{
	char	*temp;
	char	*bucket_trim;

	bucket_trim = ft_strchr(bucket, '\n');
	if (!bucket_trim)
	{
		free(bucket);
		bucket = NULL;
		return (NULL);
	}
	temp = ft_strdup(bucket_trim + 1);
	free(bucket);
	return (temp);
}

void	*free_all(char **buffer, char **bucket)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	if (bucket && *bucket)
	{
		free(*bucket);
		*bucket = NULL;
	}
	return (NULL);
}

char	*create_new_line(char *bucket)
{
	int		i;
	char	*temp;
	char	*res;

	temp = ft_strdup(bucket);
	i = 0;
	if (temp[0] == 0)
	{
		free(temp);
		return (NULL);
	}
	while (temp[i])
	{
		if (temp[i] == '\n')
			temp[i + 1] = '\0';
		i++;
	}
	res = ft_strdup(temp);
	free(temp);
	return (res);
}
