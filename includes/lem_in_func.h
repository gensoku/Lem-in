/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_func.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 06:03:07 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/13 06:03:08 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_FUNC_H
# define LEM_IN_FUNC_H

# include "lem_in_struct.h"

/*
** parse
*/
int				parse_loop(t_env *e);
void			checking_tube(char *line, size_t num, int *breaker, t_env *e);
void			checking_room_tube(char *line, size_t num,
	int *breaker, t_env *e);
void			checking_room(char *line, size_t num, int *breaker, t_env *e);
void			checking_modifiers(char *line, size_t num,
	int *breaker, t_env *e);
void			check_integrity(t_env *e, char *line,
	int *breaker, size_t num);
void			checking_comment(char *line, size_t num,
	int *breaker, t_env *e);
void			update_rooms(t_env *e);

/*
**constructor
*/
void			push_back_err(char *line, size_t num, char *msg, t_env *e);
void			push_back_room(t_env *e, char *line, int *breaker, size_t num);
void			push_back_tube(t_env *e, char *line, int *breaker, size_t num);
void			push_err_ref(t_env *e, t_room *ref);
void			del_t_noob(t_noob *lst);

/*
**destructor
*/
void			del_t_err(t_err *errs);
void			del_t_room(t_room *lst);
void			del_t_tube(t_tubes *lst);
void			display_er(t_env *e, int is_exit);
void			del_t_t_room(t_t_room *lst);

/*
**lib_tools
*/
int				is_not_valid(char c);
int				ft_isnum_str(char *str);
int				modifier_on(int	*breaker);
void			print_color(char *color, char *msg, int fd, size_t num);
char			*get_color_(int nb, char type);
int				len_rooms(t_room *rooms);

/*
**getters
*/
t_room			*get_room(char *name, t_room *lst);
int				is_tube_set(char *line, t_tubes *lst);
int				is_link_set(t_room *r, char *name);

/*
**debug
*/
void			print_content(t_env *e, t_room *r, t_tubes *t);
void			print_content_part_2(t_env *e);

/*
**algo
*/
int				resolve_algo(t_env *e);
int				is_path_set(char *name, t_t_room *paths);
t_t_room		*push_back_link(char *name, t_t_room *path, t_env *e);
void			push_back_path(t_env *e, t_t_room *path);
void			destroy_path(t_t_room **path);
t_t_room		*cpy_path(t_t_room *path, t_env *e);
t_noob			*push_noob(t_env *e, t_t_room *path, t_noob *all);
void			optimise_path(t_env *e);
int				exclude_path(t_t_room *path, t_t_room *best, t_noob *stack);
size_t			len_path(t_t_room *path);
void			send_ants(t_env *e, size_t ant_num);
int				update_ants(t_noob *lst, t_env *e,
	t_noob *tmp, t_t_room *tmp2);
void			try_send(t_noob *path, size_t *ant_num,
	size_t *last_path, t_env *e);
void			display_ants(t_room *room, size_t ant, t_env *e);
t_t_room		*dump_path(t_t_room *path, t_t_room *cur, t_env *e);
int				cmp_path2(t_t_room *s1, t_t_room *s2);
int				already_found(t_t_room *path, t_env *e);
void			corrupt_dist(t_env *e);
t_room			*get_lowest_path(t_room *lst, t_room *dodge);

#endif
