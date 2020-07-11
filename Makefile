# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/04 07:46:49 by tsedigi           #+#    #+#              #
#    Updated: 2017/05/04 07:46:50 by tsedigi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in
#CFLAGS = -Wall -Wextra -Werror -Weverything -fsanitize=address -g
#CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror

ALL_CFLAGS = $(CFLAGS)

LIBFLAGS = -L./libs/libft -lft

#	Ojects/Sources directories
INC_lem_in = includes/ 
SRC_lem_in = $(shell find src | grep "\.c$$" | sed "s/\.c$$//g")
INCLUDES += $(addprefix -iquote , $(INC_lem_in))
SRCS += $(addsuffix .c, $(SRC_lem_in))
#	Extern includes

INC_LIBS = libs/libft/includes 
INCLUDES += $(addprefix -iquote , $(INC_LIBS))

 #	Final OBJS
OBJS = $(SRCS:.c=.o)

#	Layout
VERBOSE = true

all: header $(NAME) footer

header:
	@echo "\033[33m[\033[4m$(NAME)\033[0m\033[33m] Compile\033[0m"

footer:
	@echo "\033[33m[\033[4m$(NAME)\033[0m\033[33m] Finished\033[0m"

$(NAME): llibft $(OBJS)
ifeq ($(VERBOSE),true)
	@echo "\033[34m. Compile Final .\033[0m $(NAME)"
else
	@printf"\033[34m.\033[0m"
endif
	@$(CC) $(ALL_CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) -g $(LIBFLAGS)

%.o: %.c 
ifeq ($(VERBOSE),true)
	@echo "\033[34m. Compile .\033[0m $<"
else
	@printf"\033[34m.\033[0m"
endif
	@$(CC) $(ALL_CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo -e "\033[33m[\033[4m$(NAME)\033[0m\033[33m] >>\033[0m \033[31mCLEAN all object files (*.o)\033[0m"
	@$(RM) $(OBJS)

fclean: clean
	@echo -e "\033[33m[\033[4m$(NAME)\033[0m\033[33m] >>\033[0m \033[31mFCLEAN project binary ($(NAME))\033[0m"
	@$(RM) $(NAME)

re:fclean all

llibft:
	@echo "\033[33m[\033[4m$(NAME)\033[0m\033[33m] >> Extern dependencies\033[0m"
	@make -C libs/libft
	@echo "\033[33m[\033[4m$(NAME)\033[0m\033[33m] << Extern dependencies\033[0m"

llibftclean:
	make -C libs/libft clean

llibftfclean:
	make -C libs/libft fclean

llibftre:
	make -C libs/libft re

