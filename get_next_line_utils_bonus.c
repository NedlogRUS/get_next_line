/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:27:45 by apanikov          #+#    #+#             */
/*   Updated: 2023/04/07 17:27:50 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*new;
	int		j;

	j = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!new)
	{
		return (0);
	}
	while (s1[j])
	{
		new[j] = s1[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	char	f;

	if (!s)
		return (NULL);
	f = (char)c;
	while (*s)
	{
		if (*s == f)
			return ((char *)s);
		s++;
	}
	if (*s == f)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	int		i;

	if (!s1)
		return (ft_strdup(s2));
	i = 0;
	arr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!arr)
		return (NULL);
	while (*s1)
		arr[i++] = *s1++;
	if (!s2)
		return (arr);
	while (*s2)
		arr[i++] = *s2++;
	arr[i] = '\0';
	return (arr);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		c;

	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	c = len;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (*s && start > 0)
	{
		s++;
		start--;
	}
	while (*s && len > 0)
	{
		*str++ = *s++;
		len--;
	}
	*str = '\0';
	str -= c;
	return (str);
}
