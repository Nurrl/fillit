/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:29:52 by lroux             #+#    #+#             */
/*   Updated: 2018/11/18 20:20:23 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	readcf(char (*bf)[21], int ds)
{
	int		rt;
	char	dummy;

	if ((rt = read(ds, *bf, 20)) < 0 || rt != 20)
		return ((rt == 0) ? RCF_EOF : RCF_FAIL);
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
** - All '#' are adjacent either vertically or horizontally
*/
static int	rcheckf(char *bf)
{
	size_t first;

	if (ft_cc(bf, '#') != 4 || ft_cc(bf, '.') != 12 || ft_cc(bf, '\n') != 4)
		return (RCF_FAIL);
	/* Check for adjacent */
	first = ft_strchr(bf, '#');

	return (RCF_KEK);
}

static int	rcfill(t_fill **list, char *bf)
{
	return (RCF_KEK);
}

/*
** Function with following routine:
** -> Read (the file)
** -> Check (the buffer)
** -> Fill (the linked list)
*/

int			rcf(t_fill **list, char *filename)
{
	int		rt;
	int		ds;
	char	bf[21];

	(void)list;
	if (!(ds = open(filename, O_RDONLY)))
		return (RCF_FAIL);
	while ((rt = readcf(&bf, ds)) != RCF_EOF)
	{
		if (rt == RCF_FAIL)
			return (RCF_FAIL);
		if (rcheckf(bf) == RCF_FAIL)
			return (RCF_FAIL);
		if (rcfill(list, bf) == RCF_FAIL)
			return (RCF_FAIL);
	}
	close(ds);
	return (RCF_KEK);
}
