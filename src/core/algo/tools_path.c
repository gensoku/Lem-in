/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 08:37:18 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/09 08:37:19 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				is_path_set(char *name, t_t_room *paths)
{
	t_t_room	*tmp;

	if (!paths)
		return (0);
	tmp = paths;
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_t_room		*push_back_link(char *name, t_t_room *path, t_env *e)
{
	t_t_room	*node;
	t_t_room	*tmp;

	node = (t_t_room *)ft_memalloc((sizeof(t_t_room)));
	(!node) ? display_er(e, 1) : 0;
	node->name = ft_strdup(name);
	if (!path)
		return (node);
	tmp = path;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
	return (path);
}

void			push_back_path(t_env *e, t_t_room *path)
{
	t_t_room	*lst;
	t_t_room	*tmp;
	t_noob		*node;
	t_noob		*t_p;

	tmp = path;
	lst = NULL;
	while (tmp)
	{
		lst = push_back_link(tmp->name, lst, e);
		tmp = tmp->next;
	}
	(!lst) ? e->max = 1 : 0;
	node = (t_noob *)ft_memalloc((sizeof(t_noob)));
	(!node) ? display_er(e, 1) : 0;
	node->path = lst;
	t_p = e->resolved;
	if (!t_p)
		e->resolved = node;
	else
	{
		while (t_p->next)
			t_p = t_p->next;
		t_p->next = node;
	}
}

void			destroy_path(t_t_room **path)
{
	t_t_room	*tmp;
	t_t_room	*tmp2;

	if (!path || !*path)
		return ;
	tmp = *path;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		ft_memdel((void **)&tmp2->name);
		ft_memdel((void **)&tmp2);
	}
	*path = NULL;
}
