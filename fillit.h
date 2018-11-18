/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:21:40 by lroux             #+#    #+#             */
/*   Updated: 2018/11/18 18:32:21 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>

typedef struct		s_fill {
	size_t			h;
	size_t			w;
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
