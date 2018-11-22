/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:04:35 by lroux             #+#    #+#             */
/*   Updated: 2018/11/22 11:04:57 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_sqrt(unsigned int nb)
{
	unsigned int a;
	unsigned int b;

	a = 0x8000;
	b = 0x8000;
	while (1)
	{
		if (b * b > nb)
			b ^= a;
		a >>= 1;
		if (a == 0)
			return (b);
		b |= a;
	}
}
