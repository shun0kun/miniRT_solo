#include "minirt.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_minirt	rt;

	if (argc != 2)
	{
		printf("a");
		return (1);
	}
	if (!minirt_init(&rt, argv[1]))
	{
		printf("b");
		return (1);
	}
	minirt_run(&rt);
	return (0);
}
