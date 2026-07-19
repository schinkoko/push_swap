/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:09:48 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/05/03 18:39:50 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*temp;
	ssize_t		bytes_read;
	char		*clean_line;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	bytes_read = read_line(fd, temp, &line);
	free(temp);
	if (bytes_read < 0 || !line || !*line)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	clean_line = extract_line(line);
	line = trim_line(line);
	return (clean_line);
}

/*int	main(void) {
	int		fd = open("./test.txt", O_RDONLY);
	char	*res;

	while ((res = get_next_line(fd))) {
		size_t	i = 0;

		printf("\"");
		while (res[i]) {
			if (res[i] == '\n')
				printf("\\n");
			else
				printf("%c", res[i]);
			i++;
		}
		free(res);
		printf("\"\n");
		printf("-----\n");
	}
	printf("%s\n", res);
	free(res);
}*/
