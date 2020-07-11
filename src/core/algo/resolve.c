/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 05:39:47 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/06 05:39:48 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_t_room		*try_get_end(t_t_room *lst, t_env *e)
{
	t_t_room		*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, e->end->name))
			return (tmp);
		tmp = tmp->next;
	}
	return (lst->next);
}

static int			not_optimised(t_t_room *locked, t_t_room *path)
{
	t_t_room		*tmp;
	t_t_room		*tmp2;

	tmp = locked;
	tmp2 = path;
	if (!tmp || !tmp2)
		return (0);
	while (tmp2)
	{
		tmp = locked;
		while (tmp)
		{
			if (!ft_strcmp(tmp->name, tmp2->name))
				return (1);
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
	return (0);
}

static int			unknow_path(t_t_room *path, t_env *e)
{
	t_noob			*lst;

	if (!path || !e->resolved || !e->resolved->path)
		return (1);
	lst = e->resolved;
	while (lst && lst->path)
	{
		if (not_optimised(lst->path, path))
			return (0);
		lst = lst->next;
	}
	return (1);
}

static int			resolve_path(t_env *e, t_t_room *cur,
	t_t_room *path, t_room *r)
{
	if (!cur)
	{
		destroy_path(&path);
		return (0);
	}
	if (!ft_strcmp(cur->name, e->end->name))
	{
		if (!path)
			e->max = 1;
		if (path && !already_found(path, e))
			push_back_path(e, path);
		destroy_path(&path);
		return (1);
	}
	if (!is_path_set(cur->name, path) && ft_strcmp(cur->name, e->start->name))
	{
		r = get_room(cur->name, e->rooms);
		if (unknow_path(path, e))
			resolve_path(e, r ? r->lst : NULL, dump_path(path, cur, e), NULL);
	}
	return (resolve_path(e, try_get_end(cur->next, e), path, r));
}

int					resolve_algo(t_env *e)
{
	t_t_room		*links;
	t_room			*r;

	if (!e->start || !e->end || !e->rooms || !e->tubes_lst ||
		!e->start->lst || !e->end->lst)
	{
		print_color(YELLOW, "ERROR\n", 2, 0);
		return (0);
	}
	links = e->start->lst;
	while (links)
	{
		r = get_room(links->name, e->rooms);
		resolve_path(e, links, NULL, NULL);
		links = links->next;
	}
	return ((e->max || (e->resolved && e->resolved->path)) ? 1 : 0);
}
