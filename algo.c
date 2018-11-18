#include "fillit.h"

char	*create_map(int	size)
{
	char	*map;
	int		sq_size;

	sq_size = ft_sqrt(size * 4);
	map = (char*)malloc(sizeof(*map) * sq_size);
	ft_memset(map, '0', sq_size);
	return (map)
}

void	find_square(t_fill *list, int list_size)
{
	char	*map;

	map = create_map(list_size);
	fill_map(map, list, list_size);
	free(map);
}
