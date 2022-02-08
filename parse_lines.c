#include "fdf.h"


void del(void *point)
{
	free(point);
}

t_list *parse_lines(char *file, int *w, int *h)
{
	int		y;
	int		fd;
	char	*line;
	t_list	*list;

	y = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return NULL;
	list = list_new();
	if (!list)
			return NULL;
	line = get_next_line(fd);
	while (line)
	{
		*w = parse_line(line, list, y);
		free(line);
		if (*w == -1)
		{
			list_del(&list, del);
			return NULL;
		}
		line = get_next_line(fd);
		y++;
	}
	*h = y;
	return list;
}