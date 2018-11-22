/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:24:21 by lroux             #+#    #+#             */
/*   Updated: 2018/11/22 10:33:45 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	filladd(t_fill **list, t_fill *new)
{
	t_fill *iter;

	if (!new || !list)
		return ;
	if (!*list)
		*list = new;
	else
	{
		iter = *list;
		while (iter && iter->next)
			iter = iter->next;
		iter->next = new;
	}
}

int		filllen(t_fill *list)
{
	int len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}

void	fillfree(t_fill **list)
{
	t_fill *tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
	*list = NULL;
}
