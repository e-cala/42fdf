/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:37:43 by ecabanas          #+#    #+#             */
/*   Updated: 2023/06/26 10:57:15 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h> 
# include <unistd.h> // read() function
# include <fcntl.h> // open() function
# include "defines.h"

/*      utils.c         */
int		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	map_init(t_map	*map);
void	print_map(t_meta meta);

/*      plot_line.c     */
void	drawline(t_meta *meta);
void	plot_line(t_meta *meta, t_point start, t_point end);

/*      read_fd.c       */
int		read_file(char *filename, t_map *map);

/*		key_hooks		*/
int		key_press(int keycode, t_meta *meta);

/*      get_next_line.c */
char	*get_next_line(int fd);

/*      errors.c        */
void	free_double_pointer(char **ptr);
int		ft_destroy_window(t_vars *vars);
void	err(char *str);

/*      draw_map.c      */
void	draw_map(t_meta *meta);
void	draw_points(t_meta *meta, t_point *copy_points);

/*      transformations.c*/
void	zoom(t_point *point, int len, float scale);
void	ft_reduce_z(int len, t_point *points, float divisor);

/***************/
void	rotation_x(int len, t_point *points, t_point *projected, int ang);
void	rotation_y(int len, t_point *points, t_point *projected, int ang);
void	rotation_z(int len, t_point *points, t_point *projected, int ang);
int		ft_mouse_down(int mousecode, int x, int y, t_meta *meta);

#endif
