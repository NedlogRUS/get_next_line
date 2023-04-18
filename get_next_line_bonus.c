/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:26:51 by apanikov          #+#    #+#             */
/*   Updated: 2023/04/07 17:26:58 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *buffer)
{
	int		i;
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	i = 1;
	while (!ft_strchr (buffer, '\n') && i > 0)
	{
		i = read (fd, buf, BUFFER_SIZE);
		if (i < 0)
		{
			free (buffer);
			return (NULL);
		}
		buf[i] = '\0';
		tmp = buffer;
		buffer = ft_strjoin(buffer, buf);
		free (tmp);
	}
	return (buffer);
}

char	*rebuffer(char *buffer)
{
	char	*tmp;
	int		len;

	if (ft_strchr(buffer, '\n'))
	{
		tmp = buffer;
		len = ft_strlen(ft_strchr(buffer, '\n') + 1);
		buffer = ft_substr(buffer, ft_strlen(buffer) - len, len);
		free (tmp);
		tmp = NULL;
	}
	else
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*ft_out(char *buffer)
{
	char	*out;
	int		lk;

	lk = ft_strlen(buffer);
	if (ft_strchr(buffer, '\n'))
		out = ft_substr(buffer, 0, lk - ft_strlen(ft_strchr(buffer, '\n') + 1));
	else
		out = ft_strdup(buffer);
	return (out);
}

char	*get_next_line(int fd)
{
	char static	*buffer[OPEN_MAX];
	char		*out;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd > OPEN_MAX)
		return (NULL);
	buffer[fd] = read_line(fd, buffer[fd]);
	if (buffer[fd][0] == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	out = ft_out(buffer[fd]);
	buffer[fd] = rebuffer(buffer[fd]);
	return (out);
}
