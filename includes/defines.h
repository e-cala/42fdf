/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:13:15 by ecabanas          #+#    #+#             */
/*   Updated: 2023/03/15 17:13:16 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIN_WIDTH  720 //1920
# define WIN_HEIGHT 720 // 1080
# define X 0
# define Y 1
# define Z 2

# define WHITE 	0x0FFFFFF
# define RED 	0x0FF0000
# define YELLOW 0x0FFFF00
# define GREEN 	0x0FF000

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}t_vars;

typedef struct s_point {
	int	axis[3];
	int	color;
}	t_point;

typedef struct s_map {
	t_point	*points;
}	t_map;

typedef struct s_meta {
	t_vars	vars;
	t_data	data;
	t_map	map;
}	t_meta;

#endif
