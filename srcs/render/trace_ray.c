#include "render.h"

bool	object_hit(const t_ray ray, const t_object *object, t_hit *hit)
{
	
	return (true);
}

bool	find_nearest_hit(const t_ray ray, const t_object *objects, t_hit *hit)
{
	t_object	*obj;
	t_hit		nearest;
	t_hit		tmp;

	obj = objects;
	object_hit(ray, obj, &nearest);
	while (obj)
	{
		if (object_hit(ray, obj, &tmp) && nearest.t > tmp.t)
			nearest = tmp;
		obj = obj->next;
	}
	*hit = nearest;
	return (true);
}

t_vec3	hit_normal(const t_hit *hit)
{
	t_vec3	normal;

	return (normal);
}

t_color	shade_hit(const t_scene *scene, const t_hit *hit, t_vec3 normal)
{
	t_color	color;

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
