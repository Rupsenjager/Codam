/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 12:31:03 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/11/21 15:08:23 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*pointer;
	int		length;
	int		i;
	int		j;

	j = 0;
	i = 0;
	length = ft_strlen(str2);
	if (str1)
		length += ft_strlen(str1);
	pointer = malloc(sizeof(char) * length + 1);
	if (!pointer)
		return (ft_free(&pointer));
	while (str1 && str1[i])
	{
		pointer[i] = str1[i];
		i++;
	}
	while (str2 && str2[j])
		pointer[i++] = str2[j++];
	pointer[i] = '\0';
	free(str1);
	return (pointer);
}
