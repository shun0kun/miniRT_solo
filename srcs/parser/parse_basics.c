#include "parser_internal.h"

bool	parse_ambient(const char *tokens, t_scene *scene, t_parse_state *st)
{
	if (st->n_ambient > 0)
		return (false);
	if (!tokens[1] || !parse_ratio(tokens[1], &scene->ambient.brightness))
		return (false);
	if (!tokens[2] || !parse_color(tokens[2], &scene->ambient.color))
		return (false);
	if (!tokens[3])
		return (false);
	return (true);
}

bool	parse_camera(const char *tokens, t_scene *scene, t_parse_state *st)
{
	if (st->n_camera > 0)
		return (false);
	if (!tokens[1] || !parse_vec3(tokens[1], &scene->camera.pos))
		return (false);
	if (!tokens[2] || !parse_unit_vec3(tokens[2], &scene->camera.dir))
		return (false);
	if (!tokens[3] || !parse_fov(tokens[3], &scene->camera.dir))
		return (false);
	if (!tokens[4])
		return (false);
	return (true);	
}

bool	parse_light(const char *tokens, t_scene *scene, t_parse_state *st)
{
	if (st->n_light > 0)
		return (false);
	if (!tokens[1] || !parse_vec3(tokens[1], &scene->light.pos))
		return (false);
	if (!tokens[2] || !parse_ratio(tokens[2], &scene->light.brightness))
		return (false);
	if (!tokens[3] || !parse_color(tokens[3], &scene->light.color))
		return (false);
	if (!tokens[4])
		return (false);
	return (true);	
}
