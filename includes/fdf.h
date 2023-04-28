/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:37:43 by ecabanas          #+#    #+#             */
/*   Updated: 2023/01/10 12:11:31 by ecabanas         ###   ########.fr       */
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
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*      plot_line.c     */
void    drawline(t_meta *meta);
void	plot_line(t_meta *meta, t_point start, t_point end);


/*		key_hooks		*/
int		esc_hook(int keycode, t_vars *vars);
#endif
