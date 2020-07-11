/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_err_ref.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 08:37:02 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/01 08:37:03 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		push_err_ref(t_env *e, t_room *ref)
{
	t_err	*tmp;

	if (!e || !e->errs)
		display_er(e, 1);
	tmp = e->errs;
	while (tmp->next)
		tmp = tmp->next;
	tmp->ref = ref;
}
