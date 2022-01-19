#include "fdf.h"

t_point lerp(t_point p0, t_point p1)
{
	int dx = abs(p0.x - p1.x);
	int dy = abs(p0.y - p1.y);
	int sx = (p0.x < p1.x) ? 1 : -1;
	int sy = (p0.y < p1.y) ? 1 : -1;
	int err = dx - dy;
	int e2;

	while (p0.x != p1.x || p0.y != p1.y)
	{
		e2 = 2 * err;
		if (e2 + dy >= 0)
		{
			err -= dy;
			p0.x += sx;
		}
		if (e2 - dy <= 0)
		{
			err += dx;
			p0.y += sy;
		}
		return p0;
	}
	return p0;
}
void print_point(t_point p)
{
	printf("point : {%d, %d}\n", p.x, p.y);
}

void fill(t_data *img, t_point p0, t_point p1, t_point p2,int color)
{
	t_point p = p0;
	while (p.x != p1.x || p.y != p1.y)
	{
		p = lerp(p, p1);
		draw_line(img, p, p2, color);
	}
}
void fill_triangle(t_data *img, t_point p0, t_point p1, t_point p2,int color)
{
	fill(img, p0, p1, p2,color);
	fill(img, p2, p0, p1,color);
	fill(img, p2, p1, p0,color);
}
