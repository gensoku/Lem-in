/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 06:03:15 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/13 06:03:16 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_STRUCT_H
# define LEM_IN_STRUCT_H

typedef	struct		s_t_room
{
	char			*name;
	int				empty;
	size_t			ant_num;
	int				dist;
	struct s_t_room	*next;
	struct s_t_room	*prev;
}					t_t_room;

typedef	struct		s_noob
{
	t_t_room		*path;
	size_t			size;
	struct s_noob	*next;
}					t_noob;

typedef struct		s_tubes
{
	char			*name1;
	char			*name2;
	char			*full;
	char			*full_rotate;
	struct s_tubes	*next;
}					t_tubes;

typedef struct		s_room
{
	size_t			num_line;
	int				start;
	int				end;
	int				dist;
	int				x;
	int				y;
	t_t_room		*lst;
	char			*name;
	struct s_room	*next;
}					t_room;

typedef struct		s_err
{
	char			*msg;
	size_t			num_line;
	char			*line;
	t_room			*ref;
	struct s_err	*next;
}					t_err;

typedef struct		s_env
{
	t_err			*errs;
	t_room			*rooms;
	t_room			*start;
	t_room			*end;
	t_tubes			*tubes_lst;
	unsigned long	opts;
	int				breaker;
	int				ants;
	int				max;
	size_t			turn_send;
	size_t			total;
	t_noob			*resolved;
}					t_env;

#endif
