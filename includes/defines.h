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

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

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

typedef struct s_line {
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	color;
}	t_line;

#endif
