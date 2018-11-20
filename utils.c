/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:43:36 by lroux             #+#    #+#             */
/*   Updated: 2018/11/20 16:08:01 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		translate(t_fill *list, t_point move)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		list->points[i].x += move.x;
		list->points[i].y += move.y;
	}
}

static t_point	maxmove(t_fill *list)
{
	char	mx;
	char	my;
	int		i;

	mx = 3;
	my = 3;
	i = -1;
	while (++i < 4)
	{
		if (list->points[i].x < mx)
			mx = list->points[i].x;
		if (list->points[i].y < my)
			my = list->points[i].y;
	}
	return ((t_point){-mx, -my});
}

void			moveorigin(t_fill *list)
{
	while (list)
	{
		translate(list, maxmove(list));
		list = list->next;
	}
}
