/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimise_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 08:41:38 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/09 08:41:39 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_noob				*push_noob(t_env *e, t_t_room *path, t_noob *all)
{
	t_t_room		*lst;
	t_noob			*node;
	t_noob			*t_p;

	lst = cpy_path(path, e);
	node = (t_noob *)ft_memalloc((sizeof(t_noob)));
	(!node) ? display_er(e, 1) : 0;
	node->path = lst;
	node->size = len_path(lst) + 1;
	if (!all)
		return (node);
	else
	{
		t_p = all;
		while (t_p->next)
			t_p = t_p->next;
		t_p->next = node;
	}
	return (all);
}

t_t_room			*cpy_path(t_t_room *path, t_env *e)
{
	t_t_room		*ret;
	t_t_room		*tmp;

	ret = NULL;
	tmp = path;
	while (tmp)
	{
		ret = push_back_link(tmp->name, ret, e);
		tmp = tmp->next;
	}
	return (ret);
}

size_t				len_path(t_t_room *path)
{
	size_t			ret;
	t_t_room		*tmp;

	ret = 0;
	if (path)
	{
		tmp = path;
		while (tmp)
		{
			ret++;
			tmp = tmp->next;
		}
	}
	return (ret);
}

t_t_room			*get_best_path(t_noob *all, t_t_room *last, t_noob *stack)
{
	t_noob			*tmp;
	t_t_room		*ret;
	size_t			size;

	tmp = all;
	size = 0;
	ret = NULL;
	while (tmp)
	{
		tmp->size = !tmp->size ? len_path(tmp->path) : tmp->size;
		if ((tmp->size < size || (size == 0 && tmp->size > 0)) &&
			exclude_path(tmp->path, last, stack))
		{
			ret = tmp->path;
		}
		tmp = tmp->next;
	}
	return (ret);
}

void				optimise_path(t_env *e)
{
	t_noob			*tmp;
	t_t_room		*best;

	best = get_best_path(e->resolved, NULL, NULL);
	tmp = NULL;
	if (best)
	{
		while (best)
		{
			tmp = push_noob(e, best, tmp);
			best = get_best_path(e->resolved, best, tmp);
		}
	}
	if (tmp)
	{
		del_t_noob(e->resolved);
		e->resolved = tmp;
	}
}
