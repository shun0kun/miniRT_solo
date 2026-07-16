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

void	image_init(t_image *image, void *mlx);
void	image_destroy();
void	image_put_pixel(int x, int y, t_color color);

#endif
