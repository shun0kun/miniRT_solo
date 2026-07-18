#include "color.h"

t_color	color_new(double r, double g, double b)
{
	t_color	new;

	new.r = r;
	new.g = g;
	new.b = b;
	return (new);
}

int	color_to_int(t_color color)
{
	return ((unsigned int)color.r << 16 | (unsigned int)color.g << 8 | (unsigned int)color.b);
}
