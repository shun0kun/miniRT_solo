#include "parser_internal.h"
#include <stdlib.h>

bool	parse_sphere(const char **tokens, t_scene *scene)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (false);
	if (!tokens[1] || !parse_vec3(tokens[1], &obj->data.sphere.center))
		return (false);
	if (!tokens[2] || !parse_positive_double(tokens[2], &obj->data.sphere.radius))
		return (false);
	if (!tokens[3] || !parse_color(tokens[3], &obj->color))
		return (false);
	if (!tokens[4])
		return (false);
	// sceneのtailにくっつける。
	return (true);
}

bool	parse_plane(const char **tokens, t_scene *scene)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (false);
	if (!tokens[1] || !parse_vec3(tokens[1], &obj->data.plane.point))
		return (false);
	if (!tokens[2] || !parse_normal_vec3(tokens[2], &obj->data.plane.normal))
		return (false);
	if (!tokens[3] || !parse_color(tokens[3], &obj->color))
		return (false);
	if (!tokens[4])
		return (false);
	// sceneのtailにくっつける。
	return (true);
}

bool	parse_cylinder(const char **tokens, t_scene *scene)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (false);
	if (!tokens[1] || !parse_vec3(tokens[1], &obj->data.cylinder.center))
		return (false);
	if (!tokens[2] || !parse_unit_vec3(tokens[2], &obj->data.cylinder.axis))
		return (false);
	if (!tokens[3] || !parse_positive_double(tokens[3], &obj->data.cylinder.radius))
		return (false);
	if (!tokens[4] || !parse_positive_double(tokens[4], &obj->data.cylinder.radius))
		return (false);
	if (!tokens[5] || !parse_color(tokens[4], &obj->color))
		return (false);
	if (!tokens[6])
		return (false);
	// sceneのtailにくっつける。
	return (true);
}
