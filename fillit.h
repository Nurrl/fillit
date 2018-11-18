/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:21:40 by lroux             #+#    #+#             */
/*   Updated: 2018/11/18 19:00:06 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>

typedef struct		s_point{
	char			x;
	char			y;
}					t_point;

typedef struct		s_fill {

	t_point			points[4];
	char			letter;
	struct s_fill	*next;
}					t_fill;

# define RCF_FAIL -1
# define RCF_KEK 0
# define RCF_EOF 1

void			usage(char *name);
void			error(void);
void			clean(void);
int				rcf(t_fill **list, char *filename);

#endif
