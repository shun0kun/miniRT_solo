#ifndef SCENE_H
# define SCENE_H

# include "vec3.h"
# include "color.h"

typedef enum object_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER
}	t_object_type;

typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	point;
	t_vec3	normal;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	axis;
	double	radius;
	double	height;
}	t_cylinder;

typedef union u_object_data
{
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_object_data;

typedef struct s_object
{
	t_object_type	type;
	t_object_data	data;
	t_color			color;
	struct s_object	*next;
}	t_object;

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
	t_color	color;
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
	t_object*	objects;
}	t_scene;

void	scene_clear(t_scene *scene);
void	scene_add_object(t_scene *scene, t_object *object);

#endif
