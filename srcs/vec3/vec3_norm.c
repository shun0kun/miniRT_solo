#include "vec3.h"
#include <math.h>

double	vec3_len(t_vec3 v)
{
	return (hypot(hypot(v.x, v.y), v.z));
}

double	vec3_len2(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vec3	vec3_normalize(t_vec3 v)
{
	double	len;

	len = vec3_len(v);
	if (len == 0.0)
		return (vec3_new(0.0, 0.0, 0.0));
	return (vec3_scale(v, 1.0 / len));
}
