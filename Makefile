# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/02 17:30:38 by pasosa-s          #+#    #+#              #
#    Updated: 2019/05/28 16:42:40 by pasosa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I fillit.h

L_DIR = ./libft

LIBFT = $(L_DIR)/libft.a

SRCS = count_adj_blocks.c \
	   create_board.c \
	   fillit.c \
	   is_placeable.c \
	   is_valid_file.c \
	   main.c \
	   place_tetro.c \
	   save_tetros.c \
	   free_mem.c


OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@(cd $(L_DIR) && $(MAKE))
	@(gcc $(FLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME))

clean:
		rm -f $(OBJ)
		@(cd $(L_DIR) && $(MAKE) $@)

fclean: clean
		rm -f $(NAME)
		@(cd $(L_DIR) && $(MAKE) $@)

re: fclean all
