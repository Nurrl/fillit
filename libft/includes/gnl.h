/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:23:09 by lroux             #+#    #+#             */
/*   Updated: 2018/11/18 15:11:53 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# ifndef BUFF_SIZE
#  define BUFF_SIZE 4096
# endif

# define GNL_READ 1
# define GNL_EOF 0
# define GNL_ERR -1

typedef struct			s_gnldata
{
	char				data[BUFF_SIZE + 1];
	int					descriptor;
	struct s_gnldata	*prev;
	struct s_gnldata	*next;
}						t_gnldata;

int						gnl(const int fd, char **line);

#endif
