#ifndef RENDER_H
# define RENDER_H

# include "scene.h"
# include "image.h"
# include "ray.h"
# include "vec3.h"

# define HIT_EPSILON	1e-6

typedef struct s_hit
{
	t_ray		ray;
	t_object	*object;
	double		t;
	t_vec3		point;
}	t_hit;

void	render(const t_scene *scene, t_image *image);

t_ray	camera_ray(const t_camera *camera, const t_image *image, int x, int y);

t_color	trace_ray(const t_scene *scene, const t_ray ray);
bool	find_nearest_hit(t_ray const ray, t_object *objects, t_hit *hit);

bool	object_hit(t_ray const ray, t_object *object, t_hit *hit);
bool	sphere_hit(t_ray const ray, t_object *object, t_hit *hit);
bool	plane_hit(t_ray const ray, t_object *object, t_hit *hit);
bool	cylinder_hit(t_ray const ray, t_object *object, t_hit *hit);

#endif
