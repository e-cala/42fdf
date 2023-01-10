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
#2. mejorar el tema de AFLAGS y regla $(NAME)
#3. crear directorios para ficherros .o y .d
#4. anadir norma para dependencias de ficheros

NAME		=	fdf
MLX			=	minilibx_macos/
HEADER		=	includes/fdf.h

SRC_PATH 	=	src/
SRC			=	main.c
SRCS		=	$(addprefix $(SRC_PATH), $(SRC))
OBJ			=	$(SRCS:.c=.o)
MINILIBX	=	-L ./lib/$(MLX) -lmlx
FRAMEWORK	=	-framework OpenGL -framework AppKit

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
AFLAGS		=	-L lib/libft -lft

RM			= rm -f

##########################################################################
all: $(NAME)

#$(NAME): $(OBJ) $(HEADER)
#	$(CC) $(CFLAGS) -I $(HEADER) $(OBJ) -o $@

libft:
	make -C lib/libft

$(NAME): libft $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) $(OBJ) $(MINILIBX) ./lib/libft/libft.a $(FRAMEWORK) -o $@

clean:
	make -C lib/libft clean
	$(RM) $(OBJ)

fclean: clean
	make -C lib/libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


#%.o: %.c
#	$(CC) $(CFLAGS) -I$(mlx) -c $< -o $@
#
#$(NAME): $(OBJ)
#	$(CC) $(OBJ) -L$(mlx) -l$(mlx) -framework -OpenGL AppKit -o $(NAME)


