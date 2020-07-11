/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 06:57:43 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/01 06:57:44 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_ants(t_env *e, char *line, size_t num, int *breaker)
{
	if (e->ants == -1)
	{
		push_back_err(line, num, ANTS_NOT_SET, e);
		*breaker = 0 | ERR_BREAKER;
		return (1);
	}
	return (0);
}

void		checking_modifiers(char *line, size_t num, int *breaker, t_env *e)
{
	if (check_ants(e, line, num, breaker))
		return ;
	if (modifier_on(breaker))
	{
		if (ft_strcmp(line, "##start") && ft_strcmp(line, "##end"))
			push_back_err(line, num, MODIFIER_FORMAT, e);
		push_back_err(line, num, EXPECT_ROOM_NOT_MODIFIER, e);
		*breaker = 0 | ERR_BREAKER;
	}
	else if (ft_strcmp(line, "##start") && ft_strcmp(line, "##end"))
	{
		push_back_err(line, num, MODIFIER_FORMAT, e);
		*breaker = 0 | ERR_BREAKER;
	}
	else if (!ft_strcmp(line, "##start"))
	{
		*breaker = (e->start) ? 0 | ERR_BREAKER : 0 | START_FLAG;
		(e->start) ? push_back_err(line, num, START_ALREADY_SET, e) : 0;
	}
	else if (!ft_strcmp(line, "##end"))
	{
		*breaker = (e->end) ? 0 | ERR_BREAKER : 0 | END_FLAG;
		(e->end) ? push_back_err(line, num, END_ALREADY_SET, e) : 0;
	}
}
