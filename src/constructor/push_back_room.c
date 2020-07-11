/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_room.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 07:14:24 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/01 07:14:25 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	assign_room(t_env *e, t_room *node, t_room *tmp, int *breaker)
{
	if (!e->rooms)
		e->rooms = node;
	else
	{
		tmp = e->rooms;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	*breaker = 0;
	node->start ? e->start = node : 0;
	node->end ? e->end = node : 0;
}

void		push_back_room(t_env *e, char *line, int *breaker, size_t num)
{
	char	**arr;
	t_room	*tmp;
	t_room	*node;

	arr = ft_strsplit(line, ' ');
	(!arr) ? display_er(e, 1) : 0;
	if ((tmp = get_room(arr[0], e->rooms)))
	{
		push_back_err(arr[0], num, ROOM_DUPLICATE, e);
		push_err_ref(e, tmp);
		*breaker = 0 | ERR_BREAKER;
		ft_del_tab((void ***)&arr);
		return ;
	}
	(!(node = (t_room *)ft_memalloc(sizeof(t_room)))) ? display_er(e, 1) : 0;
	node->x = ft_atoi(arr[1]);
	node->y = ft_atoi(arr[2]);
	node->dist = -1;
	node->name = ft_strdup(arr[0]);
	node->start = (*breaker & START_FLAG) ? 1 : 0;
	node->end = (*breaker & END_FLAG) ? 1 : 0;
	node->num_line = num;
	assign_room(e, node, NULL, breaker);
	ft_del_tab((void ***)&arr);
	arr = NULL;
}
