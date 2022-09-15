# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 13:20:43 by rsiqueir          #+#    #+#              #
#    Updated: 2022/09/14 22:53:37 by rsiqueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

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

all: $(NAME)

%.o:    %.c
	$(CC) $(CFLAGS) -I./include -c $< -o $@

$(NAME):		$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY:	all clean fclean re