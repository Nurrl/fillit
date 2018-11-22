/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:51:17 by lroux             #+#    #+#             */
/*   Updated: 2018/11/22 12:55:20 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(t_fill **ls)
{
	if (ls)
		fillfree(ls);
	ft_putstr("error\n");
	exit(1);
}

int		clean(t_fill **ls, char *map)
{
	if (map)
		free(map);
	if (ls)
		fillfree(ls);
	return (1);
}
