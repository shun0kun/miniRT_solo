#include "parser_internal.h"
#include <stdlib.h>

bool	parse_sphere(const char **tokens, t_scene *scene)
{
	t_object	*obj;
	bool		ret;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (false);
	ret = true;
	if (!tokens[1] || !parse_vec3(tokens[1], &obj->data.sphere.center))
		ret = false;
	if (!tokens[2] || !parse_positive_double(tokens[2], &obj->data.sphere.radius))
		ret = false;
	if (!tokens[3] || !parse_color(tokens[3], &obj->color))
		ret = false;
	if (!tokens[4])
		ret = false;
	if (ret == false)
	{
		free(obj);
		return (ret);
	}
	scene_add_object(scene, obj);
	return (ret);
}

bool	parse_plane(const char **tokens, t_scene *scene)
{
	t_object	*obj;
	bool		ret;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (false);
	ret = true;
	if (!tokens[1] || !parse_vec3(tokens[1], &obj->data.plane.point))
		ret = false;
	if (!tokens[2] || !parse_normal_vec3(tokens[2], &obj->data.plane.normal))
		ret = false;
	if (!tokens[3] || !parse_color(tokens[3], &obj->color))
		ret = false;
	if (!tokens[4])
		ret = false;
	if (ret == false)
	{
		free(obj);
		return (ret);
	}
	scene_add_object(scene, obj);
	return (ret);
}

bool	parse_cylinder(const char **tokens, t_scene *scene)
{
	t_object	*obj;
	bool		ret;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (false);
	ret = true;
	if (!tokens[1] || !parse_vec3(tokens[1], &obj->data.cylinder.center))
		ret = false;
	if (!tokens[2] || !parse_unit_vec3(tokens[2], &obj->data.cylinder.axis))
		ret = false;
	if (!tokens[3] || !parse_positive_double(tokens[3], &obj->data.cylinder.radius))
		ret = false;
	if (!tokens[4] || !parse_positive_double(tokens[4], &obj->data.cylinder.radius))
		ret = false;
	if (!tokens[5] || !parse_color(tokens[4], &obj->color))
		ret = false;
	if (!tokens[6])
		ret = false;
	if (ret == false)
	{
		free(obj);
		return (ret);
	}
	scene_add_object(scene, obj);
	return (obj);
}
