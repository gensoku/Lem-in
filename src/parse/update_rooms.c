/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 04:24:18 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/06 04:24:19 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		push_back_local_tube(t_room *r, char *link, t_env *e)
{
	t_t_room	*node;
	t_t_room	*tmp;

	if (!r || !link)
		return ;
	node = (t_t_room *)ft_memalloc((sizeof(t_t_room)));
	(!node) ? display_er(e, 1) : 0;
	node->name = ft_strdup(link);
	tmp = r->lst;
	if (!tmp)
		r->lst = node;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

static int		check_links_set(t_room *tmp, t_room *tmp2, t_env *e, int op)
{
	if (!op)
	{
		if (!is_link_set(tmp, tmp2->name) &&
			(ft_strcmp(tmp2->name, e->start->name) ||
			!ft_strcmp(tmp->name, e->end->name)))
		{
			return (1);
		}
	}
	else
	{
		if (!is_link_set(tmp2, tmp->name) &&
			(ft_strcmp(tmp->name, e->start->name) ||
			!ft_strcmp(tmp2->name, e->end->name)))
		{
			return (1);
		}
	}
	return (0);
}

static void		update_local_tube(t_room *tmp, t_room *tmp2,
	t_tubes *t, t_env *e)
{
	tmp = get_room(t->name1, e->rooms);
	tmp2 = get_room(t->name2, e->rooms);
	if (!tmp)
		push_back_err(t->name1, 0, UNKNOW_ROOM, e);
	if (!tmp2)
		push_back_err(t->name2, 0, UNKNOW_ROOM, e);
	if (tmp && tmp2)
	{
		if (check_links_set(tmp, tmp2, e, 0))
			push_back_local_tube(tmp, tmp2->name, e);
		if (check_links_set(tmp, tmp2, e, 1))
			push_back_local_tube(tmp2, tmp->name, e);
	}
}

void			update_rooms(t_env *e)
{
	t_tubes		*t;

	t = e->tubes_lst;
	if (!e->end || !e->start)
		return ;
	while (t)
	{
		update_local_tube(NULL, NULL, t, e);
		t = t->next;
	}
}
