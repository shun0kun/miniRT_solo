#include <stdio.h>
#include "libft.h"

void	zeros(float mat[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mat[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int	i;
	int	j;
	float	res[4][4];
	const float	mat[4][4] = {{1, 2, 3, 4},
							{0, 0, 1, 0},
							{9, 9, 9, 9},
							{2, 0, 2, 5}};
	
	zeros(res);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%f, ", res[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	ft_memcpy(res, mat, sizeof(mat));
	printf("\n----------------------------\n");
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%f, ", res[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}