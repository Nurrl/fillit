/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:23:35 by pscott            #+#    #+#             */
/*   Updated: 2018/11/21 18:23:58 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	empty_map(void)
{
	t_map empty;

	empty.w = 0;
	empty.size = 0;
	empty.map = NULL;
	return (empty);
}

t_map	create_map(int map_width)
{
	t_map	map;
	int		i;

	map.w = map_width;
	map.size = map.w * (map.w - 1);
	if (!(map.map = (char*)malloc(sizeof(map) * (map.size + 1))))
		return (empty_map());
	ft_memset(map.map, '.', map.size);
	map.map[map.size] = 0;
	i = map.w - 1;
	while (i < map.size)
	{
		map.map[i] = '\n';
		i += map.w;
	}
	return (map);
}
