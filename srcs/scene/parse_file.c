#include "scene.h"
#include "scene_internal.h"
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"

bool	parse_line(const char *line, t_scene *scene, t_parse_state *st)
{
	char	**tokens;
	bool	ret;

	// tokens = ft_split(line, " \t\n\v\f\r");
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (false);
	if (!tokens[0]) // ft_splitが空行をかえしてくれる前提。ft_splitの仕様を要確認
		ret = true;
	else if (ft_strcmp(tokens[0], "A") == 0)
		ret = parse_ambient(tokens, scene, st);
	else if (ft_strcmp(tokens[0], "C") == 0)
		ret = parse_camera(tokens, scene, st);
	else if (ft_strcmp(tokens[0], "L") == 0)
		ret = parse_light(tokens, scene, st);
	else if (ft_strcmp(tokens[0], "sp") == 0)
		ret = parse_sphere(tokens, scene);
	else if (ft_strcmp(tokens[0], "pl") == 0)
		ret = parse_plane(tokens, scene);
	else if (ft_strcmp(tokens[0], "cy") == 0)
		ret = parse_cylinder(tokens, scene);
	else
		ret = false;
	ft_strs_free(tokens);
	return (ret);
}

bool	parse_file(char const *path, t_scene *scene)
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
			close(fd);
			scene_clear(scene);
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
