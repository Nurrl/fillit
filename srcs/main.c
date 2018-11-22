/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:20:40 by lroux             #+#    #+#             */
/*   Updated: 2018/11/22 10:30:43 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_fill	*ls;
	t_map	map;

	if (ac != 2)
		usage(av[0]);
	ls = NULL;
	if (rcf(&ls, av[1]) == RCF_FAIL)
		error(&ls);
	moveorigin(ls);
	map = create_map((int)ft_sqrt((unsigned int)filllen(ls) * 4));
	master_function(ls, &map);
	ft_putstr(map.map);
	fillfree(&ls);
	free(map.map);
	return (0);
}
