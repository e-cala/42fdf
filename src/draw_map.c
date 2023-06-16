#include "../lib/minilibx_macos/mlx.h"
#include "../includes/fdf.h"
#include "../includes/defines.h"

static void    copy_map_points(t_point *src, t_point *dst, int total_size)
{
    int i;

    i = 0;
    while (i < total_size)
    {
        dst[i] = src[i];
        i++;
    }
}

static void	center_point_in_window(int len, t_point *points, t_point distance)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].axis[X] += distance.axis[X];
		points[i].axis[Y] += distance.axis[Y];
		points[i].axis[Z] += distance.axis[Z];
		i++;
	}
}

void	draw_line(t_meta *meta, int len, t_map *map, t_point *proyected)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (i >= len - (int)map->limits.axis[X])
			plot_line(meta, proyected[i], proyected[i + 1]);
		else if (i == 0 || (i + 1) % (int)map->limits.axis[X] != 0)
		{
			plot_line(meta, proyected[i], proyected[i + 1]);
			plot_line(meta, proyected[i], proyected[i + \
				(int)map->limits.axis[X]]);
		}
		else
			plot_line(meta, proyected[i], proyected[i + \
				(int)map->limits.axis[X]]);
		i++;
	}
}

void    black_background(t_data *data)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y <= WIN_HEIGHT)
    {
        x = 0;
        while (x <= WIN_WIDTH)
        {
            my_mlx_pixel_put(data, x, y, BLACK);
            x++;
        }
        y++;
    }
}


void    draw_map(t_meta *meta)
{
    t_point *copy_points;
    
    copy_points = malloc(meta->map.total_size * sizeof * copy_points);
    black_background(&meta->data);
    copy_map_points(meta->map.points, copy_points, meta->map.total_size);
    //ft_reduce_z(meta->map.total_size, copy_points, meta->map.divisor);
    //zoom(copy_points, meta->map.total_size, meta->map.scale);
    rotation_x(meta->map.total_size, copy_points, copy_points, meta->map.ang[X]);
    rotation_y(meta->map.total_size, copy_points, copy_points, meta->map.ang[Y]);
    rotation_z(meta->map.total_size, copy_points, copy_points, meta->map.ang[Z]);
    center_point_in_window(meta->map.total_size, copy_points, meta->map.source);
    draw_line(meta, meta->map.total_size, &meta->map, copy_points);
    free(copy_points);
    mlx_put_image_to_window(meta->vars.mlx, meta->vars.win, meta->data.img, 0, 0);
}


/********************************/
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

