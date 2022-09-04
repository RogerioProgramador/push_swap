# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 13:20:43 by rsiqueir          #+#    #+#              #
#    Updated: 2022/09/03 21:16:50 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
PUSH = push

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRCS =	src/main.c				\
		src/allocate.c			\
		src/lib_functions.c		\
		src/stack_functions.c	\
		src/operations.c 		\
		src/radix.c 			\
		src/sort.c				\
		src/validate_args.c

OBJS = $(SRCS:%.c=%.o)

all: $(PUSH) 

limpo: all clean

$(PUSH):		$(OBJS)
					$(CC) $(CFLAGS)  $(OBJS) -o $(PUSH)

clean:
	$(RM) src/*.o

fclean: clean
	$(RM) $(PUSH) 

re: fclean all

bonus: all

.PHONY:	all clean fclean re bonus