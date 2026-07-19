/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 22:13:04 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/19 22:47:52 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_len(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

ssize_t	read_line(int fd, char *temp, char **line)
{
	ssize_t	bytes_read;
	size_t	i;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		i = 0;
		while (*line != NULL && (*line)[i] && (*line)[i] != '\n')
			i++;
		if (*line && (*line)[i] == '\n')
			break ;
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (-1);
		temp[bytes_read] = '\0';
		if (bytes_read > 0)
			*line = append(*line, temp);
		if (!*line)
			return (-1);
	}
	return (bytes_read);
}

char	*extract_line(char *line)
{
	char	*to_return;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	to_return = malloc(i + 1);
	if (!to_return)
		return (NULL);
	while (j < i)
	{
		to_return[j] = line[j];
		j++;
	}
	to_return[j] = '\0';
	return (to_return);
}

char	*trim_line(char *line)
{
	char	*trimmed;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	trimmed = malloc(ft_len(line) - i + 1);
	if (!trimmed)
		return (NULL);
	while (line[i])
		trimmed[j++] = line[i++];
	trimmed[j] = '\0';
	free(line);
	return (trimmed);
}

char	*append(char *line, char *temp)
{
	size_t	i;
	size_t	j;
	char	*new_line;

	new_line = malloc(ft_len(line) + ft_len(temp) + 1);
	if (!new_line)
		return (free(line), NULL);
	i = 0;
	j = 0;
	while (line && line[j])
		new_line[i++] = line[j++];
	j = 0;
	while (temp[j])
		new_line[i++] = temp[j++];
	new_line[i] = '\0';
	free(line);
	return (new_line);
}
