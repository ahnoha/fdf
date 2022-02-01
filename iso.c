#include "fdf.h"

t_point iso(int x, int y, int z)
{
	t_point p;
    int previous_x;
    int previous_y;

    previous_x = x * 10;
    previous_y = y * 10;
    p.x = (previous_x - previous_y) * cos(0.523599);
    p.y = (-z) + (previous_x + previous_y) * sin(0.523599);
	return p;
}