/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juamolin <juamolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:03:22 by juamolin          #+#    #+#             */
/*   Updated: 2024/12/08 13:44:00 by juamolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_update_buffer(char *buffer)
{
	int		i;
	char	*new_buffer;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	new_buffer = ft_substr(buffer, i, (ft_strlen(buffer) - i));
	if (!new_buffer)
		return (NULL);
	free(buffer);
	return (new_buffer);
}

static char	*ft_return_line(char *buffer)
{
	int		i;
	char	*save_line;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	save_line = ft_substr(buffer, 0, i);
	return (save_line);
}

static char	*ft_read_fd(int fd, char *buffer)
{
	int		cont;
	char	*temp_buffer;

	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(sizeof(char) * 1);
		if (!buffer)
			return (free(temp_buffer), NULL);
		buffer[0] = '\0';
	}
	cont = 1;
	while (!ft_strchr(buffer, '\n') && cont > 0)
	{
		cont = read(fd, temp_buffer, BUFFER_SIZE);
		if (cont == -1)
			return (free(buffer), free(temp_buffer), NULL);
		temp_buffer[cont] = '\0';
		buffer = ft_strjoin(buffer, temp_buffer);
	}
	return (free(temp_buffer), buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*read_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = ft_read_fd(fd, buffer);
	if (!buffer)
		return (NULL);
	read_line = ft_return_line(buffer);
	if (read_line[0] == '\0')
	{
		free(buffer);
		free(read_line);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_update_buffer(buffer);
	return (read_line);
}
/*
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*text;

	fd = open("el_quijote.txt", O_RDONLY);
	text = get_next_line(fd);
	while (text)
	{
		printf("%s", text);
		free(text);
		text = get_next_line(fd);
	}
	close(fd);
	return (0);
}
*/