/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 14:33:57 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/11/21 13:31:02 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		ft_strlen(char *str);
int		ft_strchr(const char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*get_text(char *str, int fd);
char	*get_next_line(int fd);
char	*clean_str(char *str);
char	*remove_str(char *str);

#endif
