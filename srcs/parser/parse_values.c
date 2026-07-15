#include "parser_internal.h"
#include "libft.h"

// オーバーフロー処理する。
bool	parse_double(const char *str, double *x)
{

}

// オーバーフロー処理する。
bool	parse_int(const char *str, int *x)
{
	
}

bool	parse_vec3(const char *str, t_vec3 *v)
{
	char	**strs;

	if (!str)
		return (false);
	strs = ft_split(str, ","); // 区切り文字たくさん指定できる方の。
	if (!strs)
		return (NULL);
	if (ft_strslen(strs) != 3 || !parse_double(strs[0], &v->x) || !parse_double(strs[1], &v->y) || !parse_double(strs[2], &v->z))
	{
		free_str_arr(strs); // libftに追加してもいいかも。初期化する方も。
		return (false);
	}
	free_str_arr(strs);
	return (true);
}

// 失敗時もvの中身は代入されるけど、設計としてどうなのか考える。
bool	parse_unit_vec3(const char *str, t_vec3 *v)
{
	if (!parse_vec3(str, v) || vec3_len(*v) != 1.0) // 精度心配。本当は厳密に1なのにdouble計算によて1ではなくなる恐れがある。EPSの出番
		return (false);
	return (true);
}

// こっちも心配したときに代入されたままになる点に注意。
bool	parse_color(const char *str, t_color *color)
{
	char	**strs;

	strs = ft_split(str, ",");
	if (!strs)
		return (false);
	if (ft_strslen(strs) != 3 || !parse_int(strs[0], &color->r) || !parse_int(strs[1], &color->g) || !parse_int(strs[2], &color->b))
	{
		free_str_arr(strs);
		return (false);
	}
	free_str_arr(strs);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255 || color->b < 0 || color->b > 255)
		return (false);
	return (true);
}

bool	parse_positive_double(const char *str, double *x)
{
	if (!parse_double(str, x) || *x <= 0.0)
		return (false);
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
