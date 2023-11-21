/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 14:35:00 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/11/21 15:07:17 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_text(char *str, int fd);
char	*get_next_line(int fd);
char	*clean_str(char *str);
char	*remove_str(char *str);

// int main (void)
// {
// 	int	fd;
// 	fd = open("test.txt", O_RDONLY);

// // // while ((chars_read = read(fd, buf, 5)))
// // // {
// // // 	buf[chars_read] = '\0';
// // // 	printf("buf: %s\n", buf);
// // // }
// // // printf("%s", get_next_line(fd));
// // // printf("%s", get_next_line(fd));
// // // printf("%s", get_next_line(fd));
// // // printf("%s", get_next_line(fd));
// // // close(fd);
// // // fd = open("test.txt", O_RDONLY);
// // // printf("%s", get_next_line(fd));
// // // printf("%s", get_next_line(fd));
// // // printf("%s", get_next_line(fd));
// 	char * rups;
// 	rups = get_next_line(fd);
// 	printf("%s", rups);
// 	free(rups);

//     return (0);
// }

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	str = get_text(str, fd);
	if (!str)
		return (ft_free(&str));
	line = clean_str(str);
	str = remove_str(str);
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
			return (ft_free(&str));
		}
		else if (n == 0)
			break ;
		temp[n] = '\0';
		str = ft_strjoin(str, temp);
		if (str == NULL)
			break;
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
		ft_free(&str);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_strlen(str) - start) + 1);
	if (!temp)
		return (NULL);
	while (str[start])
		temp[i++] = str[start++];
	temp[i] = '\0';
	ft_free(&str);
	return (temp);
}

char	*ft_free (char ** input)
{
	free (*input);
	*input = NULL;
	return NULL;
}
