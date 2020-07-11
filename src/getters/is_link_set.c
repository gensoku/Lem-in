/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_link_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 06:14:02 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/08 06:14:05 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				is_link_set(t_room *r, char *name)
{
	t_t_room	*lst;

	lst = r->lst;
	if (!lst)
		return (0);
	while (lst)
	{
		if (!ft_strcmp(lst->name, name))
			return (1);
		lst = lst->next;
	}
	return (0);
}
