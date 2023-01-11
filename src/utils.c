
#include "../includes/fdf.h"
#include "../lib/libft/libft.h"
#include "../lib/minilibx_macos/mlx.h"

int	deal_key(int key, void *param)
{
	(void)key;
    (void)param;
    ft_putchar_fd('X', 1);
	return (0);
}

void    drawline(int x0, int y0, int x1, int y1, t_data *img)
{
    int dx, dy, p , x, y;

    dx = x1 - x0;
    dy = y1 - y0;
    x = x0;
    y = y0;
    p = 2 * dy - dx;
    while (x < x1)
    {
        if (p >= 0)
        {
            //putpixel(x, y, 7);
            my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
            y = y +1;
            p = p + 2 * dy * dx;
        }
        else 
        {
            //putpixel(x, y, 7);
            my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
            p = p + 2 * dy;
        }
        x = x + 1;
    }
}