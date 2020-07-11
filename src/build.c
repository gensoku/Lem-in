/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 06:30:03 by tsedigi           #+#    #+#             */
/*   Updated: 2017/05/29 06:30:04 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			print_errs(t_env *e, t_err *tmp)
{
	if (!is_opt_set(e->opts, 'd') || !e->errs)
		return ;
	tmp = e->errs;
	while (tmp)
	{
		print_color(YELLOW, tmp->msg, 2, 0);
		if (tmp->num_line)
		{
			ft_putstr_fd(" at line : ", 2);
			print_color(BLUE, NULL, 2, tmp->num_line);
		}
		if (tmp->line && ft_strlen(tmp->line))
		{
			ft_putstr_fd(" on ", 2);
			print_color(MAGENT, tmp->line, 2, 0);
		}
		if (tmp->ref)
		{
			ft_putstr_fd(" referenced at line : ", 2);
			print_color(BLUE, NULL, 2, tmp->ref->num_line);
		}
		ft_putendl_fd("", 2);
		tmp = tmp->next;
	}
}

int					main(int ac, char **av)
{
	t_env			e;
	int				ret;

	ft_bzero((void *)&e, sizeof(t_env));
	e.ants = -1;
	ret = 0;
	if (ac == 2)
	{
		if (check_opts(av[1], ALLOWED_OPTS, &e.opts, SET_OPTS) == -1)
		{
			ft_putendl_fd("invalid : usage lem_in [-dfc]", 2);
			return (1);
		}
	}
	parse_loop(&e);
	update_rooms(&e);
	print_errs(&e, NULL);
	corrupt_dist(&e);
	print_content(&e, NULL, NULL);
	ret = resolve_algo(&e);
	ret ? optimise_path(&e) : 0;
	print_content_part_2(&e);
	ret ? send_ants(&e, 0) : 0;
	display_er(&e, 0);
	return (0);
}
