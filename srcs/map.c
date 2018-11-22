/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:23:35 by pscott            #+#    #+#             */
/*   Updated: 2018/11/22 13:31:34 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	createmap(t_fill **ls, int width)
{
	t_map	map;
	int		i;

	map.w = width;
	map.size = map.w * (map.w - 1);
	if (!(map.map = malloc(sizeof(map) * (map.size + 1))))
		exit(clean(ls, NULL));
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
