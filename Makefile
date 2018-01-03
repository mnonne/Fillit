# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 17:36:48 by aminadzh          #+#    #+#              #
#    Updated: 2017/12/27 16:45:56 by aminadzh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

LIB_DIR	= ./libft
SRC_DIR	= ./src
BIN_DIR	= bin
INC_DIR	= ./includes

SRC		= filler.c \
		  main.c \
		  map.c \
		  open_file.c \
		  solver.c \
		  validator.c
OBJ		= $(addprefix $(BIN_DIR)/,$(SRC:.c=.o))

CC		= gcc
FLAGS	= -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ): | $(BIN_DIR)

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BIN_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(FLAGS) -I$(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -L$(LIB_DIR) -lft -o $(NAME)

clean:
	rm -rf $(BIN_DIR)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
