#include "get_next_line.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (!s1 || !s2)
		return ((char *)malloc(sizeof(char)));
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return ((void *)0);
	while (s1[a])
	{
		res[a] = s1[a];
		a++;
	}
	while (s2[b])
	{
		res[a] = s2[b];
		a++;
		b++;
	}
	res[a] = '\0';
	return (res);
}

char *checkmem(char *mem, char **out)
{
	char *n;

	n = 0;
	if (mem)
	{
		if ((n = ft_strchr(mem, '\n')))
		{
			*n = '\0';
			*out = ft_strdup(mem);
			ft_strcpy(mem, ++n);
		}
		else
		{
			*out = ft_strdup(mem);
			ft_strclr(mem);
		}
	}
	else
	{
		*out = ft_strnew(*out);
	}
	return(n);
}

char *get_next_line(int fd)
{
    char buf[BUFFER_SIZE + 1];
    char *out;
	char *n;
	char *tmp;
	static char *mem;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (0);
	}
	n = checkmem(mem, &out);
    while (!n && read(fd, buf, BUFFER_SIZE))
	{
		buf[BUFFER_SIZE] = '\0';
		if ((n = ft_strchr(buf, '\n')))
		{
			*n = '\0';
			mem = ft_strdup(++n);
		}
	tmp = out;
    out = ft_strjoin(out, buf);
	free(tmp);
	}
	return(out);
}

int main()
{
    int fd;
    char *out;

    fd = open("gnl.txt", O_RDONLY);
    out = get_next_line(fd);
	printf("%s\n", out);
	out = get_next_line(fd);
	printf("%s\n", out);
	out = get_next_line(fd);
	printf("%s\n", out);
	out = get_next_line(fd);
	printf("%s\n", out);
	out = get_next_line(fd);
	printf("%s\n", out);
}