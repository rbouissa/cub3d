#include"../cub3d.h"

size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_get_line(char *s)
{
	char	*p;
	int		i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	p = malloc((i + 1 + (s[i] == '\n')) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		p[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*p;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = 0;
	}
	lens1 = 0;
	lens2 = 0;
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (0);
	while (s1[lens1])
	{
		p[lens1] = s1[lens1];
		lens1++;
	}
	while (s2[lens2])
		p[lens1++] = s2[lens2++];
	p[lens1] = 0;
	free(s1);
	return (p);
}

char	*ft_reste(char *s)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	p = malloc((ft_strlen(s) - i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		p[j++] = s[i++];
	p[j] = '\0';
	free(s);
	return (p);
}