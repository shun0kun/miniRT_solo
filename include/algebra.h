#ifndef ALGEBRA_H
# define ALGEBRA_H

/* equation.c */
double	alg_discriminant(double a, double b, double c);
int		alg_solve_linear(double a, double b, double *root);
int		alg_solve_quadratic(double a, double b, double c, double roots[2]);

double	deg_to_rad(double deg);


#endif

