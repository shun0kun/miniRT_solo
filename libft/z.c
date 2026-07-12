#include <stdio.h>
#include "libft.h"

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	main(void)
{
	char	*line;
	char	**tokens;
	int		i;

	line = "1234,0x00 1 123,0x32 fw grewag";
	tokens = ft_split(line, ' ');
	i = 0;
	while (tokens[i])
	{
		printf("%s", tokens[i]);
		printf("\n");
		i++;
	}
	free_tokens(tokens);
	return (0);
}