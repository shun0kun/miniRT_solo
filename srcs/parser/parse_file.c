#include "parser.h"
#include "parser_internal.h"
#include "scene.h"
#include <fcntl.h>
#include <stdlib.h>
// #include "libft.h"

bool	parse_line(const char *line, t_scene *scene, t_parse_state *st)
{
	char	**tokens;
	bool	ret;

	tokens = ft_split(line, " \t\n\v\f\r");
	if (!tokens)
		return (false);
	if (ft_strcmp(tokens, "A") == 0)
		ret = parse_ambient(tokens, scene, st);
	else if (ft_strcmp(tokens, "C") == 0)
		ret = parse_camera(tokens, scene, st);
	else if (ft_strcmp(tokens, "L") == 0)
		ret = parse_light(tokens, scene, st);
	else if (ft_strcmp(tokens, "sp") == 0)
		ret = parse_sphere(tokens, scene);
	else if (ft_strcmp(tokens, "pl") == 0)
		ret = parse_plane(tokens, scene);
	else if (ft_strcmp(tokens, "cy") == 0)
		ret = parse_cylinder(tokens, scene);
	else
		ret = false;
	free_strs(tokens);
	return (ret);
}

bool	parse_file(const char *path, t_scene *scene)
{
	int				fd;
	char			*line;
	t_parse_state	st;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (false);
	st = (t_parse_state){0};
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!parse_line(line, scene, &st))
		{
			free(line);
			scene_clear(scene);
			close(fd);
			return (false);
		}
		free(line);
	}
	close(fd);
	if (st.n_ambient != 1 || st.n_camera != 1 || st.n_light != 1)
	{
		scene_clear(scene);
		return (false);
	}
	return (true);
}
