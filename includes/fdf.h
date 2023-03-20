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

void	drawline(t_line *line, t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*		key_hooks		*/
int		esc_hook(int keycode, t_vars *vars);
#endif
