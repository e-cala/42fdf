#include "../lib/minilibx_macos/mlx.h"
#include "../includes/fdf.h"
#include "../includes/defines.h"

void    copy_map_points(t_point *src, t_point *dst, int total_size)
{
    int i;

    i = 0;
    while (i < total_size)
    {
        dst[i] = src[i];
        i++;
    }
}

void    draw_map(t_meta *meta)
{
    t_point *copy_points;
    
    copy_points = malloc(meta->map.total_size * sizeof * copy_points);
    copy_map_points(meta->map.points, copy_points, meta->map.total_size);
    free(copy_points);
    mlx_put_image_to_window(meta->vars.mlx, meta->vars.win, meta->data.img, 0, 0);
}

void	draw_points(t_meta *meta, t_point *copy_points)
{
	int	i;

	i = 0;
	while (i < meta->map.total_size)
	{
		my_mlx_pixel_put(&meta->data, copy_points[i].axis[X] + WIN_WIDTH / 2, \
			copy_points[i].axis[Y] + WIN_HEIGHT / 2, YELLOW);
		i++;
	}
}   

