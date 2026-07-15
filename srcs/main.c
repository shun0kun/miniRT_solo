#include "minirt.h"

int	main(int argc, char **argv)
{
	t_minirt	rt;

	if (argc != 2)
		return (1);
	if (!minirt_init(&rt, argv[1]))
		return (1);
	minirt_run(&rt);
	return (0);
}
