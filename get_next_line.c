/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:16:34 by jakgonza          #+#    #+#             */
/*   Updated: 2023/06/30 11:13:44 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *store)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bits_read;

	bits_read = 1;
	if (!store)
	{
		store = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		store[0] = '\0';
	}
	while (bits_read > 0)
	{
		bits_read = read(fd, buf, BUFFER_SIZE);
		if (bits_read == -1)
			return (NULL);
		buf[bits_read] = '\0';
		store = ft_strjoin(store, buf);
		if (ft_find(store, '\n') == 0)
			break ;
	}
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*send;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
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
