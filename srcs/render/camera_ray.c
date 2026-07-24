#include <math.h>
#include "render_internal.h"
#include "ray.h"
#include "algebra.h"

t_ray	camera_ray(const t_camera *camera, const t_image *image, int x, int y)
{
	t_ray	ray;
	t_vec3	world_up;
	t_vec3	down;
	t_vec3	right;
	double	pixel_step;

	ray.origin = camera->pos;
	world_up = vec3_new(0.0, 0.0, 1.0);
	if (vec3_is_parallel(camera->dir, world_up))
		world_up = vec3_new(0.0, 1.0, 0.0);
	right = vec3_normalize(vec3_cross(camera->dir, world_up));
	down = vec3_normalize(vec3_cross(camera->dir, right));
	pixel_step = 2 * tan(deg_to_rad(camera->fov / 2.0)) / image->width;
	ray.dir = vec3_normalize(vec3_add(camera->dir,
			vec3_add(vec3_scale(right, pixel_step * (x + 0.5 - image->width / 2.0)),
			vec3_scale(down, pixel_step * (y + 0.5 - image->height / 2.0)))));
	return (ray);
}
