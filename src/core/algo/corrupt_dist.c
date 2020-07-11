/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corrupt_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 23:43:21 by tsedigi           #+#    #+#             */
/*   Updated: 2017/07/15 23:43:22 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void			push_back_stack(t_room *r, t_room **stack)
{
	while (*stack)
		stack++;
	*stack = r;
}

void			update_stack(t_room **stack, t_env *e)
{
	t_t_room	*lst;
	t_room		*cur;

	lst = (*stack)->lst;
	while (lst)
	{
		cur = get_room(lst->name, e->rooms);
		if (cur->dist == -1 && ft_strcmp(cur->name, "start"))
		{
			cur->dist = (*stack)->dist + 1;
			push_back_stack(cur, stack);
		}
		lst = lst->next;
	}
}

void			corrupt_room(t_room **stack, t_env *e)
{
	while (*stack)
	{
		update_stack(stack, e);
		stack++;
	}
}

void			sort_rec(t_t_room *cur, t_t_room *head, t_env *e)
{
	void		*p;
	int			save;
	t_room		*s;
	t_room		*s1;

	if (!cur || !cur->next)
		return ;
	s = get_room(cur->name, e->rooms);
	s1 = get_room(cur->next->name, e->rooms);
	if (!s || !s1)
		return ;
	if (s->dist > s1->dist)
	{
		p = cur->name;
		cur->name = cur->next->name;
		cur->next->name = p;
		save = cur->dist;
		cur->dist = cur->next->dist;
		cur->next->dist = save;
		return (sort_rec(head, head, e));
	}
	return (sort_rec(cur->next, head, e));
}

void			corrupt_dist(t_env *e)
{
	t_room		*r;
	t_room		**stack;

	if (!e->end || !e->start || !e->rooms || !e->tubes_lst || !e->end->lst
		|| !e->start->lst)
	{
		return ;
	}
	if (!(stack = (t_room **)ft_memalloc(sizeof(t_room *)
		* len_rooms(e->rooms) + 1)))
	{
		display_er(e, 1);
	}
	e->end->dist = 0;
	*stack = e->end;
	corrupt_room(stack, e);
	free(stack);
	r = e->rooms;
	while (r)
	{
		sort_rec(r->lst, r->lst, e);
		r = r->next;
	}
}
