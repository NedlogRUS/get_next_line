#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	a;

	a = 0;
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

char	*ft_strclr(char *str)
{
	int	a;
	int	b;

	a = 0;
	b = ft_strlen(str);
	while (a < b)
	{
		str[a] = '\0';
		a++;
	}
	return (str);
}

char	*ft_strnew(char *str)
{
	str = (char *)malloc(sizeof(char) * 1);
	if (!str)
	{
		return (0);
	}
	str[0] = '\0';
	return (str);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}