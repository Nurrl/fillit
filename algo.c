/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:11:14 by pscott            #+#    #+#             */
/*   Updated: 2018/11/20 20:39:36 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

t_map	create_map(int	map_width)
{
	t_map 	map;
	int		i;

	map.w = map_width;
	map.size = map.w * (map.w - 1);
	if (!(map.map = (char*)malloc(sizeof(map) * (map.size + 1))))
		return ((t_map){});
	ft_memset(map.map, '0', map.size);
	map.map[map.size] = 0;
	i = map.w - 1;
	while (i < map.size)
	{
		map.map[i] = '\n';
		i+= map.w;
	}
	return (map);
}

int		place_tetri(t_fill *list, t_map *map, int pos)
{
	int k;
	int	x;
	int	y;

	k = -1;
	while (++k < 4)
	{
		x = list->points[k].x;
		y = list->points[k].y;
		if (map->map[pos + x + y * map->w] != '0')
			return (0);
	}
	k = -1;
	while (++k < 4)
	{
		x = list->points[k].x;
		y = list->points[k].y;
		map->map[pos + x + y * map->w] = list->letter;
	}
	return (1);
}

int		change_pos(t_fill *list, t_map *map, int pos)
{
	if (pos == map->size + 1)
		return (0);
	if (place_tetri(list, map, pos))
		return (1);
	return (change_pos(list, map, pos + 1));
}

void	clear_letter(char letter, t_map *map)
{
	char *tmp;

	tmp = map->map;
	while (*tmp)
	{
		if (*tmp== letter)
			*tmp= '0';
		tmp++;
	}
}

int		find_square(t_fill *list, t_map *map, int pos)
{
	if (!list || pos == map->size + 1)
		return (1);
	if (change_pos(list, map, pos))
	{
		if (find_square(list->next, map, pos))
			return (1);
		clear_letter(list->letter, map);
		return (find_square(list, map, pos + 1));
	}
	return (0);
}

int		master_function(t_fill *list, t_map *map)
{
	t_map	newmap;

	if (find_square(list, map, 0))
		return (1);
	free(map->map);
	newmap = create_map(map->w + 1);
	master_function(list, &newmap);
	return (1);
}
