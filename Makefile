# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 11:25:39 by ecabanas          #+#    #+#              #
#    Updated: 2023/01/09 11:29:08 by ecabanas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#1. mejorar lib/libft

NAME		=	fdf
MLX			=	minilibx_macos/
HEADER		=	includes/fdf.h

SRC	= src
OBJ = obj
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
DEPS = $(addsuffix .d, $(basename $(SRCS)))


MINILIBX	=	-L ./lib/$(MLX) -lmlx
LIBFT		=	-L ./lib/libft -lft
FRAMEWORK	=	-framework OpenGL -framework AppKit

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -MMD

RM			= rm -rf

##########################################################################
all: $(NAME)

libft:
	make -C lib/libft

$(NAME): libft $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) $(OBJS) $(MINILIBX) $(LIBFT) $(FRAMEWORK) -o $@

$(OBJ)/%.o: $(SRC)/%.c $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ):
	mkdir $@

clean:
	make -C lib/libft clean
	$(RM) $(OBJ)

fclean: clean
	make -C lib/libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re


