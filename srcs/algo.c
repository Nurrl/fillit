/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:11:14 by pscott            #+#    #+#             */
/*   Updated: 2018/11/21 18:25:29 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		try_letter(t_fill *list, t_map *map, int pos)
{
	int k;
	int	x;
	int	y;
	int	point;

	k = -1;
	while (++k < 4)
	{
		x = list->points[k].x;
		y = list->points[k].y;
		point = pos + x + y * map->w;
		if (map->map[point] != '.' || point > map->size)
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

int		place_letter(t_fill *list, t_map *map, int pos)
{
	while (map->map[pos] != '.')
	{
		if (pos > map->size)
			return (0);
		pos++;
	}
	while (pos < map->size)
	{
		if (try_letter(list, map, pos))
			return (1);
		pos++;
	}
	return (0);
}

void	clear_letter(t_fill *list, t_map *map)
{
	char	*tmp;
	int		k;
	int		point;

	tmp = map->map;
	while (*tmp)
	{
		if (*tmp == list->letter)
		{
			k = -1;
			while (++k < 4)
			{
				point = list->points[k].x + map->w * list->points[k].y;
				*(tmp + point) = '.';
			}
			return ;
		}
		tmp++;
	}
}

int		try_map(t_fill *list, t_map *map, int pos)
{
	if (!list)
		return (1);
	if (pos > map->size)
		return (0);
	if (place_letter(list, map, pos))
	{
		if (try_map(list->next, map, 0))
			return (1);
		clear_letter(list, map);
		pos++;
		while (map->map[pos] != '.' && pos < map->size)
			pos++;
		return (try_map(list, map, pos));
	}
	return (0);
}

int		master_function(t_fill *list, t_map *map)
{
	if (!list)
		return (0);
	if (map->w > 50)
		return (0);
	if (try_map(list, map, 0))
		return (1);
	free(map->map);
	*map = create_map(map->w + 1);
	master_function(list, map);
	return (1);
}
