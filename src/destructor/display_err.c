/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 06:01:02 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/13 06:01:03 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void		display_er(t_env *e, int is_exit)
{
	del_t_err(e->errs);
	del_t_room(e->rooms);
	del_t_tube(e->tubes_lst);
	del_t_noob(e->resolved);
	ft_bzero((void *)e, sizeof(t_env));
	if (is_exit)
		exit(1);
}
