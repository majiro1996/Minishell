/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:44:47 by manujime          #+#    #+#             */
/*   Updated: 2023/03/28 19:07:11 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//reads the fd and put it's content int the buffer, if there is remainig
//tex to process from previous calls it's joined to the new read result
char	*ft_buffer_charger(int fd, char *buffer)
{
	char	*new_buffer;
	int		rd;

	new_buffer = ft_calloc_gnl((BUFFER_SIZE + 1), sizeof(char));
	rd = 1;
	while (rd != 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		rd = read(fd, new_buffer, BUFFER_SIZE);
		if (rd == -1)
		{	
			free (buffer);
			free(new_buffer);
			return (NULL);
		}
		new_buffer[rd] = '\0';
		buffer = ft_strjoin_gnl(buffer, new_buffer);
	}
	free(new_buffer);
	return (buffer);
}

//takes the content from buffer until the first \n
char	*ft_get_line(char *buffer)
{
	char	*line;
	int		c;

	c = 0;
	if (!buffer[c])
		return (NULL);
	while (buffer[c] && buffer[c] != '\n')
		c++;
	line = ft_calloc_gnl (c + 2, sizeof(char));
	c = -1;
	while (buffer[++c] && buffer[c] != '\n')
	{
		line[c] = buffer[c];
	}
	if (buffer[c] == '\n')
		line[c] = '\n';
	return (line);
}

//saves the content of buffer after the \n to process in the nex call
//if there is no more content returns null
char	*ft_save_remaining(char *buffer)
{
	char	*unused;
	int		c;
	int		k;

	c = 0;
	k = 0;
	if (!buffer)
		return (NULL);
	while (buffer[c] && buffer[c] != '\n')
		c++;
	if (!buffer[c])
	{
		free (buffer);
		return (NULL);
	}
	unused = ft_calloc_gnl((ft_strlen_gnl(buffer) - c + 1), sizeof(char));
	c++;
	while (buffer[c])
		unused[k++] = buffer [c++];
	free (buffer);
	return (unused);
}

char	*get_next_line(int fd)
{
	static char	*buffer[257];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= 257)
	{
		if (buffer[fd])
			free(buffer[fd]);
		return (NULL);
	}
	if (!buffer[fd])
		buffer[fd] = ft_calloc_gnl(1, 1);
	buffer[fd] = ft_buffer_charger(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_save_remaining(buffer[fd]);
	return (line);
}
