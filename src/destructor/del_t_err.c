/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_t_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 07:20:07 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/01 07:20:08 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		del_t_err(t_err *errs)
{
	t_err	*tmp;
	t_err	*tmp2;

	if (!errs)
		return ;
	tmp = errs;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		ft_memdel((void **)&tmp2->msg);
		ft_memdel((void **)&tmp2->line);
		tmp2->num_line = 0;
		ft_memdel((void **)&tmp2);
	}
}
