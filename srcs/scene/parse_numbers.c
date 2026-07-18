#include "scene_internal.h"
#include "libft.h"

// オーバーフロー処理する。
bool	parse_int(const char *str, int *x)
{
	*x = ft_atoi(str);
	return (true);
}

// オーバーフロー処理する。
bool	parse_double(const char *str, double *x)
{
	*x = (double)ft_atoi(str);
	return (true);	
}

bool	parse_positive_double(const char *str, double *x)
{
	if (!parse_double(str, x) || *x <= 0.0)
		return (false);
	return (true);
}