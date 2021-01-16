/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 12:27:01 by rnakai            #+#    #+#             */
/*   Updated: 2021/01/16 10:39:29 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#define BUFFER_SIZE 1000

static int		divide_and_dup_str(char **line, char **leftovers_of_each,
									char *endl_ptr, char *read_buf)
{
	char *tmp_str;

	*endl_ptr = '\0';
	if ((tmp_str = ft_strjoin("", *line)) == NULL)
		return (ERROR);
	endl_ptr++;
	if (*leftovers_of_each != NULL)
		free(*leftovers_of_each);
	if ((*leftovers_of_each = ft_strjoin("", endl_ptr)) == NULL)
		return (ERROR);
	free(*line);
	*line = tmp_str;
	free(read_buf);
	return (SUCCESS);
}

static int		free_read_buf_and_leftovers(char *read_buf,
				char **leftovers_of_each, int fd, int flag)
{
	free(read_buf);
	if (leftovers_of_each[fd])
		free(leftovers_of_each[fd]);
	return (flag);
}

static int		read_buf_and_join_str(char **line, char **leftovers_of_each,
										int fd, char *read_buf)
{
	int			read_size;
	char		*tmp_str;
	char		*endl_ptr;

	while ((read_size = read(fd, read_buf, BUFFER_SIZE)) >= 0)
	{
		read_buf[read_size] = '\0';
		if (*line)
		{
			if ((tmp_str = ft_strjoin(*line, read_buf)) == NULL)
				return (ERROR);
			free(*line);
			*line = tmp_str;
		}
		else if ((*line = ft_strjoin("", read_buf)) == NULL)
			return (ERROR);
		if ((endl_ptr = ft_strchr(*line, '\n')) != NULL)
			return (divide_and_dup_str(line, &leftovers_of_each[fd],
					endl_ptr, read_buf));
		else if (read_size == 0)
			return (free_read_buf_and_leftovers(read_buf, leftovers_of_each,
					fd, EOF_REACHED));
	}
	return (free_read_buf_and_leftovers(read_buf,
			leftovers_of_each, fd, ERROR));
}

int				get_next_line(int fd, char **line)
{
	char			*endl_ptr;
	char			*read_buf;
	static char		*(leftovers_of_each[MAX_OPEN_FILE_NUM]);

	if (fd <= -1 || BUFFER_SIZE < 1 || fd == 1 || fd == 2 ||
	line == NULL || (read_buf = (char *)malloc(BUFFER_SIZE + 1)) == NULL)
		return (ERROR);
	*line = NULL;
	if (leftovers_of_each[fd])
		*line = ft_strjoin("", leftovers_of_each[fd]);
	if (*line != NULL && (endl_ptr = ft_strchr(*line, '\n')) != NULL)
	{
		return (divide_and_dup_str(line, &leftovers_of_each[fd],
				endl_ptr, read_buf));
	}
	return (read_buf_and_join_str(line, leftovers_of_each, fd, read_buf));
}
