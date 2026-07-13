#include "parser.h"
#include "scene.h"

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (argc != 2)
		return (1);
	if (!scene_load(argv[1], &scene))
		return (1);
	render(&scene);
	scene_clear(&scene);
	return (0);
}
