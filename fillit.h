/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:21:40 by lroux             #+#    #+#             */
/*   Updated: 2018/11/20 20:39:07 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

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

void			usage(char *name);
void			error(void);
void			clean(void);
int				rcf(t_fill **list, char *filename);

//scott's testing
char	*create_map(int list_size);
int		find_square(t_fill *list, char *map, int map_size);
void	print_map(char *map, int list_size);
void	fillappend(t_fill **lst, t_fill *new);
t_fill	*fillnew(t_point *points, int num);
void	print_points(t_point *points);
void	fillprint(t_fill **lst);
void	print_map(char *map, int list_size);
#endif
