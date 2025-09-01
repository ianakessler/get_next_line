/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:56:04 by iaratang          #+#    #+#             */
/*   Updated: 2025/08/26 20:14:53 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s1);
char    *reset_bucket(char  *bucket);

char    *get_next_line(int fd)
{
    static char *bucket;
    char        *buffer;
    char        *temp;
    int         chars_read;

    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    chars_read = 1;
    if (!bucket)
        bucket = ft_calloc(1, 1);
    while (!ft_strchr(bucket, '\n'))
    {
        chars_read = read(fd, buffer, BUFFER_SIZE);
        if (chars_read <= 0)
        {
            free(buffer);
            return (bucket);
        }
        buffer[chars_read] = '\0';
        temp = ft_calloc(ft_strlen(bucket), sizeof(char));
        temp = ft_strdup(bucket);
        free(bucket);
        bucket = ft_strjoin(temp, buffer);
        free(temp);
    }
    temp = ft_strdup(bucket);
    bucket = reset_bucket(bucket);
    return (temp);
}

char    *reset_bucket(char  *bucket)
{
    char    *temp;
    char    *bucket_trim;

    bucket_trim = ft_strchr(bucket, '\n');
    if (!bucket_trim)
    {
        free(bucket);
        return (NULL);
    }
    temp = ft_strdup(bucket_trim + 1);
    free(bucket);
    return (temp);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = (void *)malloc(count * size);
	if (!tmp)
		return (NULL);
	while (tmp[i])
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(len_s1 + len_s2 + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char) c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (unsigned char) c)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy_s1;
	size_t	i;

	i = 0;
	cpy_s1 = (char *)malloc(ft_strlen(s1) + 1);
	if (!cpy_s1)
		return (NULL);
	while (s1[i])
	{
		cpy_s1[i] = s1[i];
		i++;
	}
	cpy_s1[i] = 0;
	return (cpy_s1);
}

int main(void)
{
    int fd = open("t.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
}