#include "render_internal.h"
#include "constants.h"

bool	find_nearest_hit(t_ray const ray, t_object *objects, t_hit *hit)
{
	t_object	*obj;
	t_hit		nearest;
	t_hit		tmp;
	bool		has_hit;

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

t_color	shade_hit(const t_scene *scene, const t_hit *hit, t_vec3 normal)
{
	t_color	color;
	t_ray	to_light;
	t_hit	hit_light;

	to_light = ray_new(hit->point, vec3_normalize(vec3_sub(scene->light.pos, hit->point)));
	to_light = ray_new(ray_at(to_light, EPSILON), to_light.dir);
	if (find_nearest_hit(to_light, scene->objects, &hit_light) && vec3_len2(vec3_sub(hit->point, to_light.origin)) < vec3_len3(vec3_sub(scene->light.pos, to_light.origin)))
	{
		
	}
	else
	{
		
	}
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
