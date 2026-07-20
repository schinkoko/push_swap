/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:09:48 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/20 19:11:04 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_read_until_nl(int fd, char *big_buf)
{
	int		len;
	char	*lil_buf;

	lil_buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!lil_buf)
		return (free(big_buf), NULL);
	len = 1;
	while (len && !ft_strchr(big_buf, '\n'))
	{
		len = read(fd, lil_buf, BUFFER_SIZE);
		if (len == -1)
			return (free(lil_buf), free(big_buf), NULL);
		lil_buf[len] = '\0';
		big_buf = ft_strjoin(big_buf, lil_buf);
		if (!big_buf)
			return (free(lil_buf), free(big_buf), NULL);
	}
	free(lil_buf);
	return (big_buf);
}

static char	*ft_extract_line(char *s)
{
	size_t	i;
	char	*new;

	if (!*s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	new = malloc((i + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

static char	*ft_get_rest(char *s)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i] || !s[i + 1])
		return (free(s), s = NULL, NULL);
	new = malloc((ft_strlen(s) - i + 1) * sizeof(char));
	if (!new)
		return (free(s), s = NULL, NULL);
	i++;
	j = 0;
	while (s[i])
		new[j++] = s[i++];
	new[j] = '\0';
	free(s);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*big_buf;
	char		*line;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (free(big_buf), big_buf = NULL, NULL);
	big_buf = ft_read_until_nl(fd, big_buf);
	if (!big_buf)
		return (NULL);
	line = ft_extract_line(big_buf);
	big_buf = ft_get_rest(big_buf);
	if (!line)
		return (free(big_buf), big_buf = NULL, NULL);
	return (line);
}

/* #include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("Line: %s", line);
		free(line);
	}
	close(fd);
	return (0);
} */
