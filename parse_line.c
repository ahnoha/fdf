#include "fdf.h"



int  parse_line(char *line, t_list *list, int y)
{
	char **points;
	int x;
	t_point *p;
	int i;

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
		// TODO: MAKE IT A FUNCTION GET_COLOR
		i = ft_indexof(points[x],'x');
		if (i > -1)
			p->color = to_decimal(points[x]+i+1);
		else
			p->color = 0xffffff;
		// printf("%x\n",p->color);
		add_back(list, p);
		x++;
	}
	ft_free(points, x);
	return (x);
}
