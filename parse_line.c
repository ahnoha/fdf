#include "fdf.h"

int  parse_line(char *line, t_list *list, int y)
{
	char **points;
	int x;
	t_point *p;

	x = 0;
	points = ft_split(line, ' ');
	if (!points)
		return  -1;
	while(points[x])
	{
		p = (t_point *)malloc(sizeof(t_point));
		if (!p)
		{
			ft_free(points, x);
			return -1;
		}		
		p->x = x;
		p->y = y;
		p->z = atoi(points[x]);
		p->color = 0xffffff;
		add_back(list, p);
		x++;
	}
	ft_free(points, x);
	return (x);
}
