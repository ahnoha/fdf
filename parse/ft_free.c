#include "fdf.h"

char	**ft_free(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{ 
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
