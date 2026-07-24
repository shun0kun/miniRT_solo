#ifndef RENDER_INTERNAL_H
# define RENDER_INTERNAL_H

# include "render.h"
# include "ray.h"
# include "color.h"
# include "scene.h"
# include "image.h"

# define HIT_EPSILON	1e-6

typedef struct s_hit
{
	t_ray		ray;
	t_object	*object;
	double		t;
	t_vec3		point;
}	t_hit;

t_ray	camera_ray(const t_camera *camera, const t_image *image, int x, int y);
t_color	trace_ray(const t_scene *scene, const t_ray ray);
bool	find_nearest_hit(t_ray const ray, t_object *objects, t_hit *hit);
bool	object_hit(t_ray const ray, t_object *object, t_hit *hit);
bool	sphere_hit(t_ray const ray, t_object *object, t_hit *hit);
bool	plane_hit(t_ray const ray, t_object *object, t_hit *hit);
bool	cylinder_hit(t_ray const ray, t_object *object, t_hit *hit);
t_vec3	hit_normal(const t_hit *hit);

#endif
