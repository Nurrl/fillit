/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:21:40 by lroux             #+#    #+#             */
/*   Updated: 2018/11/20 16:51:32 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>
# include <fcntl.h>

typedef struct		s_point {
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

void				filladd(t_fill **list, t_fill *new);
int					filllen(t_fill *list);
void				usage(char *name);
void				error(void);
void				clean(void);
int					rcf(t_fill **list, char *filename);
void				moveorigin(t_fill *list);

#endif
