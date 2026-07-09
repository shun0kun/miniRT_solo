#include "algebra.h"
#include <math.h>

double	alg_discriminant(double a, double b, double c)
{
	return (b * b - 4.0 * a * c);
}

int	alg_solve_linear(double a, double b, double *root)
{
	if (a == 0.0 && b != 0.0)
		return (0);
	else if (a == 0.0 && b == 0.0)
		return (-1);
	else
	{
		*root = -b / a;
		return (1);
	}
}

int	alg_solve_quadratic(double a, double b, double c, double roots[2])
{
	double	disc;
	double	sqrt_disc;

	if (a == 0.0)
		return (alg_solve_linear(b, c, roots));
	disc = alg_discriminant(a, b, c);
	if (disc < 0.0)
		return (0);
	else if (disc == 0.0)
	{
		roots[0] = -b / (2.0 * a);
		return (1);
	}
	else
	{
		sqrt_disc = sqrt(disc);
		roots[0] = (-b - sqrt_disc) / (2.0 * a);
		roots[1] = (-b + sqrt_disc) / (2.0 * a);
		return (2);
	}
}
