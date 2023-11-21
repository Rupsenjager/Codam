/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 12:16:33 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/11/21 13:30:43 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[1024];

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	str[fd] = get_text(str[fd], fd);
	if (str[fd] == NULL)
		return (NULL);
	line = clean_str(str[fd]);
	str[fd] = remove_str(str[fd]);
	return (line);
}

char	*get_text(char *str, int fd)
{
	char	*temp;
	int		n;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	n = 1;
	while (n > 0 && ft_strchr(str) == 0)
	{
		n = read(fd, temp, BUFFER_SIZE);
		if (n == -1)
		{
			free(temp);
			free(str);
			return (NULL);
		}
		else if (n == 0)
			break ;
		temp[n] = '\0';
		str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

char	*clean_str(char *str)
{
	char	*temp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	temp = malloc(sizeof(char) * i + 1);
	if (!temp)
		return (NULL);
	while (j < i)
	{
		temp[j] = str[j];
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

char	*remove_str(char *str)
{
	char	*temp;
	int		i;
	int		start;

	start = 0;
	i = 0;
	while (str[start] && str[start] != '\n')
		start++;
	if (str[start] == '\n')
		start++;
	if (str[start] == '\0')
	{
		free(str);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_strlen(str) - start) + 1);
	if (!temp)
		return (NULL);
	while (str[start])
		temp[i++] = str[start++];
	temp[i] = '\0';
	free(str);
	return (temp);
}
