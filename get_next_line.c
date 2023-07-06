/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:16:34 by jakgonza          #+#    #+#             */
/*   Updated: 2023/07/06 13:11:18 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *store)
{
	char	*buf;
	ssize_t	bits_read;

	bits_read = 1;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (bits_read > 0)
	{
		bits_read = read(fd, buf, BUFFER_SIZE);
		if (bits_read == -1)
		{
			free(store);
			free(buf);
			return (NULL);
		}
		buf[bits_read] = '\0';
		store = ft_strjoin(store, buf);
		if (ft_find(store, '\n') != 0)
			break ;
	}
	free(buf);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*send;

	if (BUFFER_SIZE <= 0 || fd == -1)
		return (NULL);
	if (!store)
	{
		store = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!store)
			return (NULL);
		store[0] = '\0';
	}
	store = ft_read(fd, store);
	if (!store)
		return (NULL);
	send = ft_send(store);
	store = ft_store(store);
	if (!store)
	{
		free(store);
		return (send);
	}
	return (send);
}
