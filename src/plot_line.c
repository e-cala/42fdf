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
#include <math.h>

void drawline(t_meta *meta)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	dx = meta->map.points[1].axis[X] - meta->map.points[0].axis[X];
	dy = meta->map.points[1].axis[Y] - meta->map.points[0].axis[Y];
	p = 2 * dy - dx;
	x = meta->map.points[0].axis[X];
	y = meta->map.points[1].axis[Y];
	while (x < meta->map.points[1].axis[X])
	{
		if (p >= 0)
		{
			my_mlx_pixel_put(&meta->data, x, y, GREEN);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			my_mlx_pixel_put(&meta->data, x, y, GREEN);
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}

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
		my_mlx_pixel_put(&meta->data, pixel.axis[X], pixel.axis[Y], start.color);
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
		my_mlx_pixel_put(&meta->data, pixel.axis[X], pixel.axis[Y], start.color);
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

/*
void	plotLineLow(t_meta *meta, int x0, int y0, int x1, int y1)
{
	int	dx = x1 - x0;
	int	dy = y1 - y0;
	int	yi = 1;
	if (dy <= 0)
	{
		yi = -1;
		dy = -dy;
	}
	int D = (2 * dy) - dx;
	int y = y0;
	for (int x = x0; x < x1; x++)
	{
		my_mlx_pixel_put(&meta->data, x, y, RED);
		if (D > 0)
		{
			y = y + yi;
			D = D + (2 * (dy -dx));
		} 
		else 
			D = D + 2 * dy;
	}
}

void	plotLineHigh(t_meta *meta, int x0, int y0, int x1, int y1)
{
	int	dx = x1 - x0;
	int	dy = y1 - y0;
	int	xi = 1;
	if (dx <= 0)
	{
		xi = -1;
		dx = -dx;
	}
	int D = (2 * dx) - dy;
	int x = x0;
	for (int y = y0; y < y1; y++)
	{
		my_mlx_pixel_put(&meta->data, x, y, GREEN);
		if (D > 0)
		{
			x = x + xi;
			D = D + (2 * (dx -dy));
		} 
		else 
			D = D + 2 * dx;
	}
}

void	plotLine(t_meta *meta, int x0, int y0, int x1, int y1)
{
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			plotLineLow(meta, x1, y1, x0, y0);
		else
			plotLineLow(meta, x0, y0, x1, y1);
	}
	else
	{
		if (y0 > y1)
			plotLineHigh(meta, x1, y1, x0, y0);
		else
			plotLineHigh(meta, x0, y0, x1, y1);

	}
}*/
