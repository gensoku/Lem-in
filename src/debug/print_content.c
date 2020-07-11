/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 03:56:04 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/06 03:56:05 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			print_ants(t_env *e)
{
	ft_putstr_fd("Ants number : ", 2);
	print_color(MAGENT, NULL, 2, e->ants);
	ft_putstr_fd("\n", 2);
}

static void			print_start_end(t_env *e)
{
	if (e->start)
	{
		ft_putstr_fd("Start room : ", 2);
		print_color(BLUE, e->start->name, 2, 0);
		ft_putendl_fd("", 2);
	}
	if (e->end)
	{
		ft_putstr_fd("End room : ", 2);
		print_color(BLUE, e->end->name, 2, 0);
		ft_putendl_fd("", 2);
	}
}

static void			print_links(t_room *r)
{
	t_t_room		*t;

	t = r->lst;
	while (t)
	{
		print_color(RED, t->name, 2, 0);
		ft_putstr_fd(t->next ? ", " : "", 2);
		t = t->next;
	}
}

static void			print_rooms(t_room *r)
{
	while (r)
	{
		ft_putstr_fd("Room : name [", 2);
		print_color(RED, r->name, 2, 0);
		ft_putstr_fd("] , coord (", 2);
		print_color(MAGENT, NULL, 2, r->x);
		ft_putstr_fd(",", 2);
		print_color(MAGENT, NULL, 2, r->y);
		ft_putstr_fd(") ", 2);
		if (r->lst)
		{
			ft_putstr_fd("links : ", 2);
			print_links(r);
		}
		ft_putendl_fd("", 2);
		r = r->next;
	}
}

void				print_content(t_env *e, t_room *r, t_tubes *t)
{
	if (is_opt_set(e->opts, 'f'))
	{
		print_ants(e);
		print_start_end(e);
		r = e->rooms;
		print_rooms(r);
		t = e->tubes_lst;
		while (t)
		{
			ft_putstr_fd("tube : ", 2);
			ft_putstr_fd(t->name1, 2);
			ft_putstr_fd(" <----> ", 2);
			ft_putendl_fd(t->name2, 2);
			t = t->next;
		}
	}
}
