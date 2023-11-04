#include"../cub3d.h"

char	*ft_read_fd(int fd, char *s)
{
	char	*p;
	int		size;

	p = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!p)
		return (NULL);
	size = 1;
	while (!ft_strchr(s, '\n') && size != 0)
	{
		size = read(fd, p, BUFFER_SIZE);
		if (size == -1)
		{
			free(p);
			free(s);
			return (0);
		}
		p[size] = '\0';
		s = ft_strjoin(s, p);
	}
	free(p);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	s = ft_read_fd(fd, s);
	if (!s)
		return (NULL);
	r = ft_get_line(s);
	s = ft_reste(s);
	return (r);
}