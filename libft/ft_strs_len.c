#include "libft.h"

size_t	ft_strs_len(char **strs)
{
	size_t	len;

	len = 0;
	while (strs[len])
		len++;
	return (len);
}
