/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:11:14 by pscott            #+#    #+#             */
/*   Updated: 2018/11/22 13:54:09 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	tryletter(t_fill *list, t_map *map, int pos)
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

static int	placeletter(t_fill *list, t_map *map, int pos)
{
	while (map->map[pos] != '.')
	{
		if (pos > map->size)
			return (0);
		pos++;
	}
	while (pos < map->size)
	{
		if (tryletter(list, map, pos))
			return (1);
		pos++;
	}
	return (0);
}

static void	clearletter(t_fill *list, t_map *map)
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

static int	trymap(t_fill *list, t_map *map, int pos)
{
	if (!list)
		return (1);
	if (pos > map->size)
		return (0);
	if (placeletter(list, map, pos))
	{
		if (trymap(list->next, map, 0))
			return (1);
		clearletter(list, map);
		pos++;
		while (map->map[pos] != '.' && pos < map->size)
			pos++;
		return (trymap(list, map, pos));
	}
	return (0);
}

int			fillit(t_fill *list, t_map *map)
{
	if (!list || !map->map || map->w > 50)
		return (0);
	if (trymap(list, map, 0))
		return (1);
	free(map->map);
	*map = createmap(&list, map->w + 1);
	fillit(list, map);
	return (1);
}
