/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_tube.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 07:14:34 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/01 07:14:35 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	*get_rotate(char **arr)
{
	char	*ret;

	if (!arr)
		return (NULL);
	ret = ft_strnew(ft_strlen(arr[0]) + ft_strlen(arr[1]) + 2);
	if (!ret)
		return (NULL);
	ft_strcat(ret, arr[1]);
	ft_strcat(ret, "-");
	ft_strcat(ret, arr[0]);
	return (ret);
}

static void	hlp_setup_tube(t_tubes *node, char **arr, char *line)
{
	node->name1 = ft_strdup(arr[0]);
	node->name2 = ft_strdup(arr[1]);
	node->full = ft_strtrim(line);
	node->full_rotate = get_rotate(arr);
}

static int	check_same_room(char **arr)
{
	if (!ft_strcmp(arr[0], arr[1]))
		return (1);
	return (0);
}

static void	attach_tube(t_env *e, t_tubes *node, t_tubes *tmp)
{
	if (!e->tubes_lst)
		e->tubes_lst = node;
	else
	{
		tmp = e->tubes_lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

void		push_back_tube(t_env *e, char *line, int *breaker, size_t num)
{
	char	**arr;
	t_tubes	*node;
	int		f;

	arr = ft_strsplit(line, '-');
	(!arr) ? display_er(e, 1) : 0;
	f = 0;
	if (is_tube_set(line, e->tubes_lst) || (f = check_same_room(arr)))
	{
		push_back_err(line, num, f ? SAME_ROOM_TUBE : TUBE_ALREADY_SET, e);
		*breaker = 0;
		ft_del_tab((void ***)&arr);
		return ;
	}
	(!(node = (t_tubes *)ft_memalloc(sizeof(t_tubes)))) ? display_er(e, 1) : 0;
	hlp_setup_tube(node, arr, line);
	attach_tube(e, node, NULL);
	*breaker = 0;
	ft_del_tab((void ***)&arr);
}
