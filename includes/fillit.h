/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:21:40 by lroux             #+#    #+#             */
/*   Updated: 2018/11/22 13:55:43 by lroux            ###   ########.fr       */
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

typedef struct		s_map {
	int				w;
	char			*map;
	int				size;
}					t_map;

# define RCF_FAIL -1
# define RCF_KEK 0
# define RCF_EOF 1

void				filladd(t_fill **list, t_fill *new);
int					filllen(t_fill *list);
void				fillfree(t_fill **list);
void				usage(char *name);
void				error(t_fill **list);
int					clean(t_fill **list, char *map);
int					rcf(t_fill **list, char *filename);
void				moveorigin(t_fill *list);

t_map				createmap(t_fill **ls, int width);
int					fillit(t_fill *list, t_map *map);

#endif
