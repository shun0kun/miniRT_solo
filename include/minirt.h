#ifndef MINIRT_H
# define MINIRT_H

# include <stdbool.h>
# include "scene.h"
# include "image.h"
# include "render.h"

typedef struct s_minirt
{
	void	*mlx;
	void	*window;
	t_image	image;
	t_scene	scene;
}	t_minirt;

bool	minirt_init(t_minirt *rt, const char *filepath);
void	minirt_run(t_minirt *rt);
void	minirt_destroy(t_minirt *rt);

#endif
