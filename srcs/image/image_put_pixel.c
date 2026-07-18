#include "image.h"

void	image_put_pixel(t_image *image, int x, int y, t_color color)
{
	*(unsigned int *)(image->pixels + y * image->line_length + x * (image->bits_per_pixel / 8)) = color_to_int(color);
}
