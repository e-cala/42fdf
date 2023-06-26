/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:44:09 by ecabanas          #+#    #+#             */
/*   Updated: 2023/06/26 10:05:03 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fdf.h"
#include "../lib/minilibx_macos/mlx.h"

int	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIN_WIDTH || y >= WIN_HEIGHT || x < 0 || y < 0)
		return (-1);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

void	zoom(t_point *point, int len, float scale)
{
	int	i;

	i = 0;
	while (i < len)
	{
		point[i].axis[X] *= scale;
		point[i].axis[Y] *= scale;
		point[i].axis[Z] *= scale;
		i++;
	}
}

void	ft_reduce_z(int len, t_point *points, float divisor)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].axis[Z] /= divisor;
		i++;
	}
}

void	map_init(t_map	*map)
{
	map->total_size = 0;
	map->limits.axis[X] = 0;
	map->limits.axis[Y] = 0;
	map->ang[X] = 0;
	map->ang[Y] = 0;
	map->ang[Z] = 0;
	map->len = 0;
	map->source.axis[X] = WIN_WIDTH / 2;
	map->source.axis[Y] = WIN_HEIGHT / 2;
	map->source.axis[Z] = 0;
	map->divisor = 1;
	map->scale = 1;
}

/*
void	draw_points(t_meta *meta, t_point *copy_points)
{
	int	i;

	i = 0;
	while (i < meta->map.total_size)
	{
			my_mlx_pixel_put(&meta->data, 30*copy_points[i].axis[X] + WIN_WIDTH / 2, \
			30*copy_points[i].axis[Y] + WIN_HEIGHT / 2, copy_points[i].color);
		i++;
	}
}
*/
