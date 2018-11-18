/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 20:02:32 by lroux             #+#    #+#             */
/*   Updated: 2018/11/13 17:03:46 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t s1len;

	s1len = ft_strlen(s1);
	if (s1len <= size)
		if (!ft_memccpy(s1 + s1len, s2, 0, size - s1len - 1))
			s1[size - 1] = 0;
	return ((s1len > size)
		? s1len + ft_strlen(s2) - (s1len - size)
		: s1len + ft_strlen(s2));
}
