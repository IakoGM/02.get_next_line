/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:24:52 by jakgonza          #+#    #+#             */
/*   Updated: 2023/06/30 12:19:22 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_find(char *buf, char c)
{
	size_t	counter;
	int		i;

	counter = 0;
	i = 0;
	if (!buf || c == '\0')
		return (0);
	while (buf[i])
	{
		if (buf[i] == c)
			return (counter);
		counter++;
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*ft_send(char *store)
{
	char	*tmp;
	int		i;

	i = 0;
	if (store[0] == '\0')
		return (NULL);
	while (store[i] != '\n' && store[i])
		i++;
	tmp = (char *) malloc ((i + 2) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (store[i] != '\n' && store[i])
	{
		tmp[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
	{
		tmp[i] = store[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_store(char *store)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	// recorro hasta \n o final
	while (store[i] != '\n' && store[i] != '\0')
		i++;
	if (store[i] == '\0')
	{
		// si es final no hay necesidad de guardar
		// porque lo que hay deberia de estar en send
		free(store);
		return (NULL);
	}
	if (store[i] == '\n')
		i++;
	tmp = (char *) malloc(sizeof(char) * (ft_strlen(store) - i + 1));
	if (!tmp)
		return (NULL);
	while (store[i])
	{
		tmp[j] = store[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	free(store);
	return (tmp);
}
