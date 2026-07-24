#include "render.h"
#include "render_internal.h"
#include "color.h"
#include "ray.h"

void	render(const t_scene *scene, t_image *image)
{
	int		x;
	int		y;
	t_ray	ray;
	t_color	color;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			ray = camera_ray(&scene->camera, image, x, y);
			color = trace_ray(scene, ray);
			image_put_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
}
