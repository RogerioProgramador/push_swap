# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 13:20:43 by rsiqueir          #+#    #+#              #
#    Updated: 2022/09/12 19:07:21 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
PUSH = push

CC = cc
CFLAGS = -g3
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

a: all clean

check:
	valgrind --show-leak-kinds=all --track-origins=yes --leak-check=full ./push 1 3 4 -5 6 -8 -9

check4:
	valgrind --show-leak-kinds=all --track-origins=yes --leak-check=full ./push -1 3 4 -5

$(PUSH):		$(OBJS)
					$(CC) $(CFLAGS)  $(OBJS) -o $(PUSH)

clean:
	$(RM) src/*.o

fclean: clean
	$(RM) $(PUSH) 

re: fclean all

bonus: all

.PHONY:	all clean fclean re bonus