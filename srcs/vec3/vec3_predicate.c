#include "vec3.h"
#include "stdbool.h"
#include "constants.h"

bool	vec3_is_zero(t_vec3 v)
{
	return (vec3_len(v) < EPSILON);
}

bool	vec3_is_parallel(t_vec3 a, t_vec3 b)
{
	if (vec3_is_zero(a) || vec3_is_zero(b))
		return (false);
	a = vec3_normalize(a);
	b = vec3_normalize(b);
	return (vec3_len(vec3_cross(a, b)) < EPSILON);
}
