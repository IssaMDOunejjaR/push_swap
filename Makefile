# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 14:53:41 by iounejja          #+#    #+#              #
#    Updated: 2021/03/15 14:27:06 by iounejja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc
FLAGS			= -Wall -Wextra -Werror
EXEC_CHECKER	= checker
EXEC_PUSH_SWAP	= push_swap
LIB_CHECKER		= checker.a
LIB_PUSH_SWAP	= push_swap.a
CHECKER_SRCS	= checker.c
PUSH_SWAP_SRCS	= push_swap.c
UTILS_SRCS		= utils/ft_strcmp.c \
					utils/tables_utils.c \
					utils/get_next_line.c \
					utils/stack_utils.c \
					utils/push_utils.c \
					utils/swap_utils.c \
					utils/rotate_utils.c \
					utils/funct_utils.c \
					utils/checker_utils.c \
					utils/push_swap_utils.c
CHECKER_OBJ		= $(CHECKER_SRCS:.c=.o)
PUSH_SWAP_OBJ	= $(PUSH_SWAP_SRCS:.c=.o)
UTILS_OBJ		= $(UTILS_SRCS:.c=.o)
INCLUDES		= -I includes/ -I libft/

all: $(EXEC_CHECKER) $(EXEC_PUSH_SWAP)

$(EXEC_CHECKER): $(UTILS_OBJ) $(CHECKER_OBJ)
				cd libft && $(MAKE) bonus
				ar rcs $(LIB_CHECKER) $(CHECKER_OBJ) $(UTILS_OBJ) libft/*.o
				$(CC) $(FLAGS) $(INCLUDES) $(LIB_CHECKER) -o $(EXEC_CHECKER)

$(EXEC_PUSH_SWAP): $(UTILS_OBJ) $(PUSH_SWAP_OBJ)
				cd libft && $(MAKE) bonus
				ar rcs $(LIB_PUSH_SWAP) $(PUSH_SWAP_OBJ) $(UTILS_OBJ) libft/*.o
				$(CC) $(FLAGS) $(INCLUDES) $(LIB_PUSH_SWAP) -o $(EXEC_PUSH_SWAP)

%.o: %.c includes/*.h libft/libft.h
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf *.o
	rm -rf utils/*.o
	rm -rf $(LIB_CHECKER)
	rm -rf $(LIB_PUSH_SWAP)
	cd libft && $(MAKE) fclean
	
fclean: clean
		rm -rf $(EXEC_CHECKER)
		rm -rf $(EXEC_PUSH_SWAP)

re: fclean all