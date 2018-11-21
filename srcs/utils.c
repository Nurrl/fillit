/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:43:36 by lroux             #+#    #+#             */
/*   Updated: 2018/11/20 17:31:28 by lroux            ###   ########.fr       */
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

void			moveorigin(t_fill *list)
{
	while (list)
	{
		translate(list, (t_point){-list->points[0].x, -list->points[0].y});
		list = list->next;
	}
}
