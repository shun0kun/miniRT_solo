#include "vec3.h"

t_vec3	vec3_new(double x, double y, double z)
{
	t_vec3	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vec3	vec3_add(t_vec3 a, t_vec3 b)
{
	return (vec3_new(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vec3	vec3_sub(t_vec3 a, t_vec3 b)
{
	return (vec3_new(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vec3	vec3_scale(t_vec3 v, double k)
{
	return (vec3_new(v.x * k, v.y * k, v.z * k));
}

t_vec3	vec3_neg(t_vec3 v)
{
	return (vec3_new(-v.x, -v.y, -v.z));
}
