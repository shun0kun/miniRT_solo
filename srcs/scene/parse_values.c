#include "scene_internal.h"
#include "libft.h"
#include "constants.h"
#include <math.h>

bool	parse_vec3(const char *str, t_vec3 *v)
{
	char	**strs;

	if (!str)
		return (false);
	strs = ft_split(str, ',');
	if (!strs)
		return (NULL);
	if (ft_strs_len(strs) != 3 || !parse_double(strs[0], &v->x) || !parse_double(strs[1], &v->y) || !parse_double(strs[2], &v->z))
	{
		ft_strs_free(strs); // libftに追加してもいいかも。初期化する方も。
		return (false);
	}
	ft_strs_free(strs);
	return (true);
}

// 失敗時もvの中身は代入されるけど、設計としてどうなのか考える。
bool	parse_unit_vec3(const char *str, t_vec3 *v)
{
	if (!parse_vec3(str, v) || fabs((vec3_len(*v) - 1.0)) > EPSILON)
		return (false);
	return (true);
}

// こっちも心配したときに代入されたままになる点に注意。
bool	parse_color(const char *str, t_color *color)
{
	char	**strs;
	int		r;
	int		g;
	int		b;

	strs = ft_split(str, ',');
	if (!strs)
		return (false);
	if (ft_strs_len(strs) != 3 || !parse_int(strs[0], &r) || !parse_int(strs[1], &g) || !parse_int(strs[2], &b))
	{
		ft_strs_free(strs);
		return (false);
	}
	ft_strs_free(strs);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (false);
	color->r = (double)r;
	color->g = (double)g;
	color->b = (double)b;
	return (true);
}

bool	parse_radius_from_diameter(const char *str, double *radius)
{
	double	diameter;

	if (!parse_positive_double(str, &diameter))
		return (false);
	*radius = diameter / 2.0;
	return (true);
}

bool	parse_ratio(const char *str, double *ratio)
{
	if (!parse_double(str, ratio) || *ratio < 0.0 || *ratio > 1.0)
		return (false);	
	return (true);
}

// こんな感じにすれば上の代入問題は解決されるが、行は長くなるし、もしかしたら余計である可能性もある。
// fov 180に対する処理は改善の余地あり。
bool	parse_fov(const char *str, double *fov)
{
	int	fov_int;

	if (!parse_int(str, &fov_int) || fov_int < 0 || fov_int > 180)
		return (false);
	if (fov_int == 180.0)
		fov_int = 179.0;
	*fov = (double)fov_int;
	return (true);
}
