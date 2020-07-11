/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_content_part_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 07:51:36 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/08 07:51:37 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			print_size(size_t size)
{
	print_color(MAGENT, " ---- : size (", 2, 0);
	print_color(YELLOW, NULL, 2, size);
	print_color(MAGENT, ")\n", 2, 0);
}

static void			print_max(t_env *e)
{
	if (e->max)
	{
		print_color(BLUE, e->start->name, 2, 0);
		ft_putstr_fd(" - ", 2);
		print_color(BLUE, e->end->name, 2, 0);
		print_size(1);
	}
}

static void			print_path(t_noob *path, int i, t_env *e, t_t_room *tmp)
{
	tmp = path->path;
	while (tmp)
	{
		if (i != 0)
		{
			ft_putstr_fd(" - ", 2);
			print_color(BLUE, tmp->name, 2, 0);
		}
		else
		{
			print_color(BLUE, e->start->name, 2, 0);
			ft_putstr_fd(" - ", 2);
			print_color(BLUE, tmp->name, 2, 0);
		}
		i++;
		if (!tmp->next)
		{
			ft_putstr_fd(" - ", 2);
			print_color(BLUE, e->end->name, 2, 0);
		}
		tmp = tmp->next;
	}
	if (path && path->size)
		print_size(path->size);
}

void				print_content_part_2(t_env *e)
{
	t_noob			*lst;

	if (is_opt_set(e->opts, 'f'))
	{
		print_color(RED, "\nList of availables Paths : \n", 2, 0);
		if (!e->max && (!e->resolved || !e->resolved->path))
			print_color(BLUE, "None !\n", 2, 0);
		else
		{
			print_max(e);
			lst = e->resolved;
			while (lst)
			{
				print_path(lst, 0, e, NULL);
				lst = lst->next;
			}
			ft_putstr_fd("\n", 2);
		}
	}
}
