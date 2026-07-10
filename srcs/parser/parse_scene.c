#include "parser.h"
#include <fcntl.h>

int	parse_scene(char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (-1);
	
}