#include "scene_internal.h"
#include "libft.h"
#include <math.h>

// オーバーフロー処理する。
bool	parse_int(const char *str, int *x)
{
	*x = ft_atoi(str);
	return (true);
}

// 設計を学ぶ。invalid文字がある場合はポインタが全く進まなくて最後の最後で弾かれるようになっている。途中で毎回invalid文字をチェックしていない点がすごい。正しいものはどんどん進んで。正しくないものは正しくない箇所で止まって最後で弾かれる。
bool	parse_double(const char *str, double *x)
{
	double	val;
	int		sign;
	bool	has_digit;
	double	scale;

	val = 0.0;
	sign = 1;
	has_digit = false;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		val += val * 10.0 + (*(str++) - '0');
		has_digit = true;
	}
	if (has_digit && *str == '.')
	{
		str++;
		scale = 0.1;
		while (ft_isdigit(*str))
		{
			val += (*str++ - '0') * scale;
			scale *= 0.1;
			has_digit = true;
		}
	}
	if (!has_digit || *str != '\0' || *str == '.' || isinfinite(val))
		return (false);
	*x = val * sign;
	return (true);	
}

bool	parse_positive_double(const char *str, double *x)
{
	if (!parse_double(str, x) || *x <= 0.0)
		return (false);
	return (true);
}