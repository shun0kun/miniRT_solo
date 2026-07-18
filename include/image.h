#ifndef IMAGE_H
# define IMAGE_H

# include "color.h"

typedef struct s_image
{
	void	*ptr;
	char	*pixels;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_image;

void	image_put_pixel(t_image *image, int x, int y, t_color color);

#endif
