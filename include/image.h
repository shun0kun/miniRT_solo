#ifndef IMAGE_H
# define IMAGE_H

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

#endif
