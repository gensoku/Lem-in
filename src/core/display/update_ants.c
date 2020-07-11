/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 05:25:09 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/13 05:25:10 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	update_to_next(t_t_room *tmp2, t_env *e)
{
	tmp2->next->empty = 1;
	tmp2->next->ant_num = tmp2->ant_num;
	display_ants(get_room(tmp2->next->name, e->rooms), tmp2->ant_num, e);
	tmp2->empty = 0;
	tmp2->ant_num = 0;
}

static void	update_to_end(t_t_room *tmp2, t_env *e)
{
	display_ants(e->end, tmp2->ant_num, e);
	tmp2->empty = 0;
	tmp2->ant_num = 0;
}

static int	update_iter(t_t_room *tmp2, t_env *e)
{
	int		ret;

	ret = 0;
	while (tmp2)
	{
		if (tmp2->empty)
		{
			if (tmp2->next)
			{
				update_to_next(tmp2, e);
				ret++;
			}
			else
			{
				update_to_end(tmp2, e);
				ret++;
			}
		}
		tmp2 = tmp2->prev;
	}
	return (ret);
}

int			update_ants(t_noob *lst, t_env *e, t_noob *tmp, t_t_room *tmp2)
{
	int		ret;

	ret = 0;
	tmp = lst;
	if (!lst)
		return (ret);
	while (tmp)
	{
		tmp2 = tmp->path;
		while (tmp2 && tmp2->next)
			tmp2 = tmp2->next;
		ret += update_iter(tmp2, e);
		tmp = tmp->next;
	}
	return (ret);
}
