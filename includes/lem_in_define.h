/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 06:03:00 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/13 06:03:01 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_DEFINE_H
# define LEM_IN_DEFINE_H

# define EMPTY_LINE	"Line is empty"
# define MODIFIER_FORMAT "Modifier is not correct, use ##start or ##end"
# define EXPECT_ROOM_NOT_MODIFIER "Expected a Room not a Modifier '##' "
# define EXPECT_ROOM_NOT_COMMENT "Expected a Room not a Comment '#' "
# define START_ALREADY_SET "The Modifier '##start' is already set"
# define END_ALREADY_SET "The Modifier '##end' is already set"
# define WRONG_FORMAT	"Line is not a valid room, tube, comment or modifier"
# define BAD_TUBE_FORMAT "Tube is not well formated, use : name1-name2 "
# define EXPECTED_ROOM_NOT_TUBE "Expected a Room not a Tube 'name1-name2' "
# define BTRC_DETAIL "Rooms cannot begin with charactere 'l' or '#' "
# define BAD_TUBE_ROOM_CHAR	"Tube is not well set : "
# define INVALID_ROOM_NAME "Room cannot begin with caractere 'l' or '#' "
# define INVALID_COORD_ROOM "Room coordinates must be numerical"
# define ROOM_DUPLICATE "Room already exist "
# define EXPECT_ROOM_NOT_EMPTY "Expected Room not an empty line"
# define NO_START_ROOM "No Room Start detected"
# define NO_END_ROOM "No End Room detected"
# define ANTS_NOT_SET "Modifier invalid number of ants are not set"
# define EXPECTED_ANTS_NB "Expected ants number"
# define ANTS_NB_INVALID_FORMAT "Ants number must be only numerical"
# define NO_ANTS_SET "Ants numbers is not set"
# define TUBE_ALREADY_SET "Tube already exists"
# define SAME_ROOM_TUBE "Tube link the same Room"
# define UNKNOW_ROOM "Room is missing referenced from a tube"

# define ERR_BREAKER 1
# define START_FLAG	 2
# define END_FLAG	 4
# define IS_ROOM	 8
# define IS_TUBE	 16

# define MAX_DEEP	 100

# define INVALID_LINE 0x1

# define ALLOWED_OPTS "dfc"

#endif
