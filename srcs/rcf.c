/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:29:52 by lroux             #+#    #+#             */
/*   Updated: 2018/11/22 13:27:45 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline int	countadj(char *bf, int x, int y)
{
	int count;

	count = 0;
	if (x > 0 && bf[y * 5 + (x - 1)] == '#')
		count++;
	if (x < 3 && bf[y * 5 + (x + 1)] == '#')
		count++;
	if (y > 0 && bf[(y - 1) * 5 + x] == '#')
		count++;
	if (y < 3 && bf[(y + 1) * 5 + x] == '#')
		count++;
	return (count);
}

static inline int	readcf(char (*bf)[21], int ds, int *hadnl)
{
	int		rt;
	char	dummy;

	if ((rt = read(ds, *bf, 20)) < 0 || rt != 20)
	{
		if (*hadnl == 1)
			return (RCF_FAIL);
		return ((rt == 0) ? RCF_EOF : RCF_FAIL);
	}
	*bf[20] = 0;
	if ((*hadnl = read(ds, &dummy, 1)) < 0)
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
	int tot;

	if (ft_cc(bf, '#') != 4 || ft_cc(bf, '.') != 12 || ft_cc(bf, '\n') != 4)
		return (RCF_FAIL);
	if (bf[4] != '\n' || bf[9] != '\n' || bf[14] != '\n' || bf[19] != '\n')
		return (RCF_FAIL);
	x = -1;
	y = 0;
	tot = 0;
	while (bf[y * 5 + ++x])
	{
		y = (x > 3) ? y + 1 : y;
		x = (x > 3) ? 0 : x;
		if (bf[y * 5 + x] == '#')
			tot += countadj(bf, x, y);
	}
	if (tot < 6)
		return (RCF_FAIL);
	return (RCF_KEK);
}

static inline int	rcfill(t_fill **ls, t_fill **iter, char *bf, size_t len)
{
	size_t	index;
	int		x;
	int		y;

	if (len > 25)
		return (RCF_FAIL);
	if (!(*iter = malloc(sizeof(t_fill))))
		exit(clean(ls, NULL));
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
	int		hadnl;
	char	bf[21];
	t_fill	*new;

	ft_bzero(bf, 21);
	if (!(ds = open(filename, O_RDONLY)))
		return (RCF_FAIL);
	hadnl = 1;
	while ((rt = readcf(&bf, ds, &hadnl)) != RCF_EOF)
	{
		if (rt == RCF_FAIL)
			return (RCF_FAIL);
		if (rcheckf(bf) == RCF_FAIL)
			return (RCF_FAIL);
		if (rcfill(list, &new, bf, filllen(*list)) == RCF_FAIL)
			return (RCF_FAIL);
		filladd(list, new);
	}
	close(ds);
	return (RCF_KEK);
}
