#ifndef VEC3_H
# define VEC3_H

# include <stdbool.h>

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

/* vec3_basic.c */
t_vec3	vec3_new(double x, double y, double z);
t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	vec3_scale(t_vec3 v, double k);
t_vec3	vec3_neg(t_vec3 v);

/* vec3_product.c */
double	vec3_dot(t_vec3 a, t_vec3 b);
t_vec3	vec3_cross(t_vec3 a, t_vec3 b);

/* vec3_norm.c */
double	vec3_len(t_vec3 v);
double	vec3_len2(t_vec3 v);
t_vec3	vec3_normalize(t_vec3 v);

/* vec3_predicate.c*/
bool	vec3_is_zero(t_vec3 v);
bool	vec3_is_parallel(t_vec3 a, t_vec3 b);

#endif
