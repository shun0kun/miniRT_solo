#ifndef PARSER_INTERNAL_H
# define PARSER_INTERNAL_H

# include <stdbool.h>
# include "scene.h"

typedef struct s_parse_state
{
	int	n_ambient;
	int	n_camera;
	int	n_light;
}	t_parse_state;

/* parse_basics.c */
bool	parse_ambient(const char **tokens, t_scene *scene, t_parse_state *st);
bool	parse_camera(const char **tokens, t_scene *scene, t_parse_state *st);
bool	parse_light(const char **tokens, t_scene *scene, t_parse_state *st);

/* parse_shapes.c */
bool	parse_sphere(const char **tokens, t_scene *scene);
bool	parse_plane(const char **tokens, t_scene *scene);
bool	parse_cylinder(const char **tokens, t_scene *scene);

/* parse_values.c */
bool	parse_color(const char *str, t_color *color);
bool	parse_vec3(const char *str, t_vec3 *v);
bool	parse_unit_vec3(const char *str, t_vec3 *v);
bool	parse_int(const char *str, int *x);
bool	parse_double(const char *str, double *x);
bool	parse_positive_double(const char *str, double *x);
bool	parse_radius_from_diameter(const char *str, double *radius);
bool	parse_ratio(const char *str, double *ratio);
bool	parse_fov(const char *str, double *fov);

#endif
