#include "fdf.h"

t_point iso(int x, int y, int z)
{
	t_point p;
 
    x = x * 20;
    y = y * 20;
    p.x = (x - y) * cos(0.523599);
    p.y = (-z) + (x + y) * sin(0.523599);
	return p;
}