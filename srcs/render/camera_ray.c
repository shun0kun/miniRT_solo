#include "render.h"
#include "ray.h"

t_ray	camera_ray(const t_camera *camera, const t_image *image, int x, int y)
{
	t_ray	ray;
	t_vec3	world_up;
	t_vec3	down;
	t_vec3	right;

	ray.origin = camera->pos;
	world_up = vec3_new(0.0, 0.0, 1.0);
	right = vec3_normalize(vec3_cross(camera->dir, world_up));
	down = vec3_normalize(vec3_cross(camera->dir, right));
	ray.dir = ;
	return (ray);
}
