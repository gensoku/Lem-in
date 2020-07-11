/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 05:10:30 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/13 05:10:33 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			check_bord_error(t_env *e, size_t num, int *breaker)
{
	if (e->ants == -1)
	{
		push_back_err("", num, NO_ANTS_SET, e);
		return (1);
	}
	if (modifier_on(breaker))
	{
		push_back_err("", num, EXPECT_ROOM_NOT_EMPTY, e);
		return (1);
	}
	else if (!e->start)
	{
		push_back_err("", num, NO_START_ROOM, e);
		return (1);
	}
	else if (!e->end)
	{
		push_back_err("", num, NO_END_ROOM, e);
		return (1);
	}
	return (0);
}

void				vefifies_line(t_env *e, int *breaker,
	size_t num_line, char *line)
{
	check_integrity(e, line, breaker, num_line);
	if (((*breaker & ERR_BREAKER) && !is_opt_set(e->opts, 'd'))
		|| e->breaker & INVALID_LINE)
	{
		e->breaker |= INVALID_LINE;
		return ;
	}
	*breaker & IS_ROOM ? push_back_room(e, line, breaker, num_line) : 0;
	*breaker & IS_TUBE ? push_back_tube(e, line, breaker, num_line) : 0;
}

int					parse_loop(t_env *e)
{
	char			*line;
	int				breaker;
	static size_t	num_line = 1;

	line = NULL;
	breaker = 0;
	while (get_next_line(0, &line) > 0 && !(e->breaker & INVALID_LINE))
	{
		vefifies_line(e, &breaker, num_line, line);
		if (e->breaker & INVALID_LINE)
		{
			ft_memdel((void **)&line);
			return (1);
		}
		num_line++;
		ft_memdel((void **)&line);
	}
	vefifies_line(e, &breaker, num_line, line);
	ft_memdel((void **)&line);
	return (check_bord_error(e, num_line, &breaker));
}
