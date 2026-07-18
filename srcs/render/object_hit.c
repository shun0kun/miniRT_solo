#include "render.h"
#include "algebra.h"

bool	select_nearest_valid_root(double const *roots, int root_count, double *selected_root)
{
	double	nearest;
	bool	found;
	int		i;

	found = false;
	if (root_count <= 0)
		return (false);
	i = 0;
	while (i < root_count)
	{
		if (roots[i] > HIT_EPSILON && (!found || roots[i] < nearest))
		{
			nearest = roots[i];
			found = true;
		}
		i++;
	}
	if (!found)
		return (false);
	*selected_root = nearest;
	return (true);
}

// 負のrootの処理。最小のtが必要。あと、EPSILONも扱う。
bool	sphere_hit(t_ray const ray, t_object *object, t_hit *hit)
{
	t_sphere const	*sphere;
	int				root_count;
	double			roots[2];

	sphere = &object->data.sphere;
	root_count = alg_solve_quadratic(
		vec3_len2(ray.dir),
		2 * vec3_dot(ray.dir, vec3_sub(ray.origin, sphere->center)),
		vec3_len2(vec3_sub(ray.origin, sphere->center)) - sphere->radius * sphere->radius,
		roots
	);
	if (!select_nearest_valid_root(roots, root_count, &hit->t))
		return (false);
	hit->ray = ray;
	hit->object = object;
	hit->point = ray_at(ray, hit->t);
	return (true);
}

bool	plane_hit(t_ray const ray, t_object *object, t_hit *hit)
{
	(void)ray;
	(void)object;
	(void)hit;
	return (false);
}

bool	cylinder_hit(t_ray const ray, t_object *object, t_hit *hit)
{
	(void)ray;
	(void)object;
	(void)hit;
	return (false);
}

bool	object_hit(t_ray const ray, t_object *object, t_hit *hit)
{
	if (!object)
		return (false);
	if (object->type == OBJ_SPHERE)
		return (sphere_hit(ray, object, hit));
	else if (object->type == OBJ_PLANE)
		return (plane_hit(ray, object, hit));
	else if (object->type == OBJ_CYLINDER)
		return (cylinder_hit(ray, object, hit));
	else
		return (false);
}
