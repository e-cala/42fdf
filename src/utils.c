/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:44:09 by ecabanas          #+#    #+#             */
/*   Updated: 2023/03/15 15:44:11 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../lib/libft/libft.h"
#include "../lib/minilibx_macos/mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	drawline(t_line *line, t_data *img)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	dx = line->x1 - line->x0;
	dy = line->y1 - line->y0;
	p = 2 * dy - dx;
	x = line->x0;
	y = line->y0;
	while (x < line->x1)
	{
		if (p >= 0)
		{
			my_mlx_pixel_put(img, x, y, line->color);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			my_mlx_pixel_put(img, x, y, line->color);
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}


// void	drawline2(t_cube *cube, t_data *img)
// {
// 	int	dx;
// 	int	dy;
// 	int	p;
// 	int	x;
// 	int	y;
// 	dx = cube->points[1].axis[X]
// 		- cube->points[0].axis[X];
// 	dy = cube->points[1].axis[Y]
// 		- cube->points[0].axis[Y];
// 	x = cube->points[0].axis[X];
// 	y = cube->points[0].axis[Y];
// 	p = 2 * dy - dx;
// 	while(x < cube->points[1].axis[X])
// 	{
// 		if (p >= 0)
// 		{
// 			my_mlx_pixel_put(img, x, y, cube->points->color);
// 			y = y + 1;
// 			p = p + 2 * dy - 2 * dx;
// 		}
// 		else
// 		{
// 			my_mlx_pixel_put(img, x, y, cube->points->color);
// 			p = p + 2 * dy;
// 		}
// 		x = x + 1;
// 	}
// }