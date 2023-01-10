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

#ifndef	fdf_h
# define fdf_h

#include <unistd.h>
#include <stdlib.h> 

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;


#endif
