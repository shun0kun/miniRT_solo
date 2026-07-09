#ifndef SCENE_H
# define SCENE_H

# include "object.h"
# include "vec3.h"
# include "color.h"

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	dir;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_vec3	pos;
	double	brightness;
}	t_light;

typedef struct s_ambient
{
	t_color	color;
	double	brightness;
}	t_ambient;

typedef struct s_scene
{
	t_camera	camera;
	t_light		light;
	t_ambient	ambient;
	t_object	*objects;
}	t_scene;

#endif
