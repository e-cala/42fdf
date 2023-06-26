/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:34:10 by ecabanas          #+#    #+#             */
/*   Updated: 2023/06/26 10:52:56 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../lib/libft/libft.h"

static void	plot_line_high(t_meta *meta, t_point s, t_point end, int xi)
{
	t_point	delta;
	t_point	pixel;
	int		pixels;

	delta.axis[X] = end.axis[X] - s.axis[X];
	delta.axis[Y] = end.axis[Y] - s.axis[Y];
	pixels = (2 * delta.axis[X]) - delta.axis[Y];
	pixel.axis[Y] = s.axis[Y];
	pixel.axis[X] = s.axis[X];
	if (delta.axis[X] < 0)
	{
		xi = -1;
		delta.axis[X] = -delta.axis[X];
	}
	while (pixel.axis[Y] < end.axis[Y])
	{
		my_mlx_pixel_put(&meta->data, pixel.axis[X], pixel.axis[Y]++, s.color);
		if (pixels > 0)
		{
			pixel.axis[X] = pixel.axis[X] + xi;
			pixels = pixels + (2 * (delta.axis[X] - delta.axis[Y]));
		}
		else
			pixels = pixels + 2 * delta.axis[X];
	}
}

static void	plot_line_low(t_meta *meta, t_point s, t_point end, int yi)
{
	t_point	delta;
	t_point	pixel;
	int		pixels;

	delta.axis[X] = end.axis[X] - s.axis[X];
	delta.axis[Y] = end.axis[Y] - s.axis[Y];
	pixels = (2 * delta.axis[Y]) - delta.axis[X];
	pixel.axis[Y] = s.axis[Y];
	pixel.axis[X] = s.axis[X];
	if (delta.axis[Y] < 0)
	{
		yi = -1;
		delta.axis[Y] = -delta.axis[Y];
	}
	while (pixel.axis[X] < end.axis[X])
	{
		my_mlx_pixel_put(&meta->data, pixel.axis[X]++, pixel.axis[Y], s.color);
		if (pixels > 0)
		{
			pixel.axis[Y] = pixel.axis[Y] + yi;
			pixels = pixels + (2 * (delta.axis[Y] - delta.axis[X]));
		}
		else
			pixels = pixels + 2 * delta.axis[Y];
	}
}

void	plot_line(t_meta *meta, t_point start, t_point end)
{
	if (ft_abs(end.axis[Y] - start.axis[Y])
		< ft_abs(end.axis[X] - start.axis[X]))
	{
		if (start.axis[X] > end.axis[X])
			plot_line_low(meta, end, start, 1);
		else
			plot_line_low(meta, start, end, 1);
	}
	else
	{
		if (start.axis[Y] > end.axis[Y])
			plot_line_high(meta, end, start, 1);
		else
			plot_line_high(meta, start, end, 1);
	}
}
