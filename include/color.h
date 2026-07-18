#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

t_color	color_new(double r, double g, double b);
int		color_to_int(t_color color);


#endif
