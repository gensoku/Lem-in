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

NAME = libft.a
#CFLAGS = -Wall -Wextra -Werror -Weverything -fsanitize=address -g
CFLAGS = -Wall -Wextra -Werror
ALL_CFLAGS = $(CFLAGS)

LIBFLAGS = -L./libs/libft

#	Ojects/Sources directories
INC_LIBFT = includes/ 
SRC_LIBFT = $(shell find src | grep "\.c$$" | sed "s/\.c$$//g")
INCLUDES += $(addprefix -iquote , $(INC_LIBFT))
SRCS += $(addsuffix .c, $(SRC_LIBFT))
#	Extern includes

INC_LIBS = 
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

$(NAME): $(OBJS)
ifeq ($(VERBOSE),true)
	@echo "\033[34m. Compile Final .\033[0m $(NAME)"
else
	@printf"\033[34m.\033[0m"
endif
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

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

