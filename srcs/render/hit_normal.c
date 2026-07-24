#include "render_internal.h"
#include "constants.h"

t_vec3	sphere_hit_normal(t_hit const *hit)
{
	t_sphere	sphere;

	sphere = hit->object->data.sphere;
	if (vec3_len(vec3_sub(sphere.center, hit->point)) == sphere.radius)
		return (vec3_new(0.0, 0.0, 0.0));
	else if (vec3_len(vec3_sub(sphere.center, hit->point)) > sphere.radius)
		return (vec3_normalize(vec3_sub(hit->point, sphere.center)));
	else
		return (vec3_normalize(vec3_sub(sphere.center, hit->point)));
}

t_vec3	plane_hit_normal(t_hit const *hit)
{
	t_plane	plane;
	double	dot;

	plane = hit->object->data.plane;
	dot = vec3_dot(vec3_sub(hit->point, plane.point), plane.normal);
	if (dot > 0)
		return (plane.normal);
	else if (dot < 0)
		return (vec3_neg(plane.normal));
	else
		return (vec3_new(0.0, 0.0, 0.0));
}

t_vec3	cylinder_hit_normal(t_hit const *hit)
{
	(void)hit;
	return ((t_vec3){0});
}

t_vec3	hit_normal(t_hit const *hit)
{
	t_vec3	normal;

	if (hit->object->type == OBJ_SPHERE)
		return (sphere_hit_normal(hit));
	else if (hit->object->type == OBJ_PLANE)
		return (plane_hit_normal(hit));
	else if (hit->object->type == OBJ_CYLINDER)
		return (cylinder_hit_normal(hit));
	return (vec3_new(0.0, 0.0, 0.0));
}
