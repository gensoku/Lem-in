/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 07:13:58 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/01 07:13:59 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		push_back_err(char *line, size_t num, char *msg, t_env *e)
{
	t_err	*tmp;
	t_err	*node;

	if (!(node = (t_err *)ft_memalloc(sizeof(t_err))))
		display_er(e, 1);
	node->msg = ft_strdup(msg);
	node->num_line = num;
	node->line = ft_strdup(line);
	tmp = e->errs;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	else
		e->errs = node;
}
