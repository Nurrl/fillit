/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:20:40 by lroux             #+#    #+#             */
/*   Updated: 2018/11/20 16:06:30 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

int	main(int ac, char **av)
{
	t_fill *ls;

	if (ac != 2)
		usage(av[0]);
	if (rcf(&ls, av[1]) == RCF_FAIL)
		error();
	moveorigin(ls);
	/* Ici 'ls' contient ta liste chainee a l'origine */
	
	/* Don't kill following comment :c */
	/*while (ls)
	{
		printf("@ Tetrimino:\nLetter: %c\nPos:\n-> (%d, %d)\n-> (%d, %d)\n-> (%d, %d)\n-> (%d, %d)\n\n",
				ls->letter, ls->points[0].x, ls->points[0].y, ls->points[1].x, ls->points[1].y, ls->points[2].x, ls->points[2].y, ls->points[3].x, ls->points[3].y);
		ls = ls->next;
	}*/
	return (0);
}
