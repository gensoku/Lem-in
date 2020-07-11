/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_t_tube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 07:20:25 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/01 07:20:26 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			del_t_tube(t_tubes *lst)
{
	t_tubes		*tmp;
	t_tubes		*tmp2;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		ft_memdel((void **)&tmp2->name1);
		ft_memdel((void **)&tmp2->name2);
		ft_memdel((void **)&tmp2->full);
		ft_memdel((void **)&tmp2->full_rotate);
		ft_memdel((void **)&tmp2);
	}
}
