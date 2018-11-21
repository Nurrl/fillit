/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:29:52 by lroux             #+#    #+#             */
/*   Updated: 2018/11/20 16:24:25 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline int	chkadj(char *bf, int x, int y)
{
	if (x > 0 && bf[y * 5 + (x - 1)] == '#')
		return (RCF_KEK);
	if (x < 3 && bf[y * 5 + (x + 1)] == '#')
		return (RCF_KEK);
	if (y > 0 && bf[(y - 1) * 5 + x] == '#')
		return (RCF_KEK);
	if (y < 3 && bf[(y + 1) * 5 + x] == '#')
		return (RCF_KEK);
	return (RCF_FAIL);
}

static inline int	readcf(char (*bf)[21], int ds, int firstread)
{
	int		rt;
	char	dummy;

	if ((rt = read(ds, *bf, 20)) < 0 || rt != 20)
	{
		if (firstread)
			return (RCF_FAIL);
		return ((rt == 0) ? RCF_EOF : RCF_FAIL);
	}
	*bf[20] = 0;
	if (read(ds, &dummy, 1) < 0)
		return (RCF_FAIL);
	return (RCF_KEK);
}

/*
** Valid file requirement:
** - 4  '#'
** - 12 '.'
** - 4  '\n'
** - Contains 4 equal lines (4chars + 1 '\n')
** - All '#' are adjacent either vertically or horizontally
*/

static inline int	rcheckf(char *bf)
{
	int x;
	int y;

	if (ft_cc(bf, '#') != 4 || ft_cc(bf, '.') != 12 || ft_cc(bf, '\n') != 4)
		return (RCF_FAIL);
	if (bf[4] != '\n' || bf[9] != '\n' || bf[14] != '\n' || bf[19] != '\n')
		return (RCF_FAIL);
	x = -1;
	y = 0;
	while (bf[y * 5 + ++x])
	{
		y = (x > 3) ? y + 1 : y;
		x = (x > 3) ? 0 : x;
		if (bf[y * 5 + x] == '#')
			if (chkadj(bf, x, y) == RCF_FAIL)
				return (RCF_FAIL);
	}
	return (RCF_KEK);
}

static inline int	rcfill(t_fill **iter, char *bf, size_t len)
{
	size_t	index;
	int		x;
	int		y;

	if (len > 25)
		return (RCF_FAIL);
	if (!(*iter = malloc(sizeof(t_fill))))
		return (RCF_FAIL);
	(*iter)->letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[len];
	(*iter)->next = NULL;
	x = -1;
	y = 0;
	index = 0;
	while (bf[y * 5 + ++x])
	{
		y = (x > 3) ? y + 1 : y;
		x = (x > 3) ? 0 : x;
		if (bf[y * 5 + x] == '#')
			(*iter)->points[index++] = (t_point){x, y};
	}
	return (RCF_KEK);
}

/*
** Function with following routine:
** -> Read (the file)
** -> Check (the buffer)
** -> Fill (the linked list)
*/

int					rcf(t_fill **list, char *filename)
{
	int		rt;
	int		ds;
	int		first;
	char	bf[21];
	t_fill	*new;

	if (!(ds = open(filename, O_RDONLY)))
		return (RCF_FAIL);
	first = 1;
	while ((rt = readcf(&bf, ds, first)) != RCF_EOF)
	{
		first = 0;
		if (rt == RCF_FAIL)
			return (RCF_FAIL);
		if (rcheckf(bf) == RCF_FAIL)
			return (RCF_FAIL);
		if (rcfill(&new, bf, filllen(*list)) == RCF_FAIL)
			return (RCF_FAIL);
		filladd(list, new);
	}
	close(ds);
	return (RCF_KEK);
}
