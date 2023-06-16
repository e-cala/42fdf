/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:34:10 by ecabanas          #+#    #+#             */
/*   Updated: 2023/04/28 11:34:11 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	plot_line_high(t_meta *meta, t_point start, t_point end)
{
	t_point	delta;
	t_point	pixel;
	int		xi;
	int		pixels;

	delta.axis[X] = end.axis[X] - start.axis[X];
	delta.axis[Y] = end.axis[Y] - start.axis[Y];
	xi = 1;
	pixels = (2 * delta.axis[X]) - delta.axis[Y];
	pixel.axis[Y] = start.axis[Y];
	pixel.axis[X] = start.axis[X];
	if (delta.axis[X] <= 0)
	{
		xi = -1;
		delta.axis[X] -= delta.axis[X];
	}
	while (pixel.axis[Y] < end.axis[Y])
	{
		//TODO:	HARDCODED COLOR TO WHITE debería cambiarlo
		my_mlx_pixel_put(&meta->data, pixel.axis[X], pixel.axis[Y], WHITE);
		if (pixels > 0)
		{
			pixel.axis[X] = pixel.axis[X] + xi;
			pixels = pixels + (2 * (delta.axis[X] - delta.axis[Y]));
		}
		else
			pixels = pixels + 2 * delta.axis[X];
		pixel.axis[Y]++;
	}
}

static void	plot_line_low(t_meta *meta, t_point start, t_point end)
{
	t_point	delta;
	t_point	pixel;
	int		yi;
	int		pixels;

	delta.axis[X] = end.axis[X] - start.axis[X];
	delta.axis[Y] = end.axis[Y] - start.axis[Y];
	yi = 1;
	pixels = (2 * delta.axis[Y]) - delta.axis[X];
	pixel.axis[Y] = start.axis[Y];
	pixel.axis[X] = start.axis[X];
	if (delta.axis[Y] <= 0)
	{
		yi = -1;
		delta.axis[Y] = -delta.axis[Y];
	}
	while (pixel.axis[X] < end.axis[X])
	{
		my_mlx_pixel_put(&meta->data, pixel.axis[X], pixel.axis[Y], WHITE);
		if (pixels > 0)
		{
			pixel.axis[Y] = pixel.axis[Y] + yi;
			pixels = pixels + (2 * (delta.axis[Y] - delta.axis[X]));
		}
		else
			pixels = pixels + 2 * delta.axis[Y];
		pixel.axis[X]++;
	}
}

void	plot_line(t_meta *meta, t_point start, t_point end)
{
	if ((abs(end.axis[Y]) - start.axis[Y]) < (abs(end.axis[X]) - start.axis[X]))
	{
		if (start.axis[X] > end.axis[X])
			plot_line_low(meta, end, start);
		else
			plot_line_low(meta, start, end);
	}
	else
	{
		if (start.axis[Y] > end.axis[Y])
			plot_line_high(meta, end, start);
		else
			plot_line_high(meta, start, end);
	}
}

