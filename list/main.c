#include "list.h"
#include <fcntl.h>
#include "get_next_line.h"
#include "fdf.h"

//0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0

void parse_line(char *line, t_list *list, int y)
{
	char **points;
	int x;
	t_point *p;
	x = 0;
	points = ft_split(line, ' ');
	while(points[x])
	{
		p = (t_point *)malloc(sizeof(t_point));
		p->x = x;
		p->y = y;
		p->z = atoi(points[x]);
		p->color = 0xffffff;
		add_back(list, p);
		x++;
	}
}
void print_list(t_list *list)
{
	t_element *elm;
	t_point *p;
	 elm = list->head;
	while (elm)
	{
		p = (t_point*)elm->content;
		printf("{%d, %d, %d} - ", p->x, p->y, p->z);
		elm = elm->next;
	}
	
}

int main(int ac, char *av[])
{
	t_list *list;
	t_element *elm;
	int fd; 
	char *line;
	int	y;


	if (ac == 2)
	{
		y = 0;
		fd = open(av[1],O_RDONLY);
		if (fd < 0)	
			return 1;
		list = list_new();
		line = get_next_line(fd);
		while (line)
		{	
			parse_line(line, list, y);		
			line = get_next_line(fd);
			y++;
		}	
		print_list(list);
	}
	
	return 0;
}