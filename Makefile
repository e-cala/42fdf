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


mlx		=	minilibx_macos/
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -I$(mlx) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L$(mlx) -l$(mlx) -framework -OpenGL AppKit -o $(NAME)
