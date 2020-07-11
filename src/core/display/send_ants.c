/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 09:29:35 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/09 09:29:36 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			display_ants(t_room *room, size_t ant, t_env *e)
{
	char		*color;
	int			nb;
	char		col;

	color = NULL;
	nb = (ant % 50) + 1;
	col = 'b';
	if (nb > 17)
	{
		col = nb > 34 ? 'r' : 'g';
		nb = nb > 34 ? nb - 34 : nb - 17;
	}
	if (is_opt_set(e->opts, 'c'))
	{
		color = get_color_(nb, col);
		ft_putstr_fd(color, 2);
	}
	ft_putstr_fd("L", 2);
	ft_putnbr_fd(ant, 2);
	ft_putstr_fd("-", 2);
	ft_putstr_fd(room->name, 2);
	ft_putstr_fd(" ", 2);
	if (is_opt_set(e->opts, 'c'))
		ft_putstr_fd(RESET, 2);
	ft_memdel((void **)&color);
}

static void		check_max(t_env *e, size_t *ant_num)
{
	if (e->max && e->ants)
	{
		display_ants(e->end, *ant_num, e);
		*ant_num += 1;
		e->ants--;
	}
}

static void		print_total(t_env *e)
{
	char		*color;

	color = NULL;
	is_opt_set(e->opts, 'c') ? color = get_color_(1, 'r') : 0;
	ft_putstr_fd("Ants were send in ", 2);
	ft_putstr_fd(color, 2);
	ft_putnbr_fd(e->turn_send + e->total, 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd(" turns.", 2);
	ft_memdel((void **)&color);
}

static void		final_checking(t_env *e)
{
	while (update_ants(e->resolved, e, NULL, NULL))
	{
		e->total++;
		ft_putstr_fd("\n", 2);
	}
	print_total(e);
}

void			send_ants(t_env *e, size_t ant_num)
{
	size_t		last_path;
	t_noob		*path;

	if (!e->ants || e->ants < 0)
		print_color(YELLOW, "No ants to send", 2, 0);
	else
	{
		ant_num = 1;
		last_path = 0;
		while (e->ants)
		{
			e->turn_send++;
			update_ants(e->resolved, e, NULL, NULL);
			check_max(e, &ant_num);
			path = e->resolved;
			while (path && e->ants)
			{
				try_send(path, &ant_num, &last_path, e);
				path = path->next;
			}
			last_path = 0;
			ft_putstr_fd("\n", 2);
		}
		final_checking(e);
	}
}
