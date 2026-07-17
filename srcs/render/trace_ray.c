#include "render.h"

bool	find_nearest_hit(t_ray const ray, t_object const *objects, t_hit *hit)
{
	t_object const	*obj;
	t_hit			nearest;
	t_hit			tmp;
	bool			has_hit;

	has_hit = false;
	obj = objects;
	while (obj)
	{
		if (object_hit(ray, obj, &tmp) && (!has_hit || nearest.t > tmp.t))
		{
			nearest = tmp;
			has_hit = true;
		}
		obj = obj->next;
	}
	if (has_hit)
		*hit = nearest;
	return (has_hit);
}

t_vec3	hit_normal(const t_hit *hit)
{
	t_vec3	normal;

	normal = vec3_new(0.0, 0.0, 0.0);
	return (normal);
}

t_color	shade_hit(const t_scene *scene, const t_hit *hit, t_vec3 normal)
{
	t_color	color;

	color = color_new(100, 50, 200);
	return (color);
}

t_color	trace_ray(const t_scene *scene, const t_ray ray)
{
	t_hit		hit;
	t_vec3		normal;
	t_color		color;

	if (!find_nearest_hit(ray, scene->objects, &hit))
		return (color_new(0.0, 0.0, 0.0));
	normal = hit_normal(&hit);
	color = shade_hit(scene, &hit, normal);
	return (color);
}
