/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:02:39 by ecabanas          #+#    #+#             */
/*   Updated: 2023/01/10 13:02:40 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx_macos/mlx.h"
#include "../lib/libft/libft.h"
#include "../includes/fdf.h"
/*
void	ft_putchar(char c, int fd)
{
	write(fd, &c, sizeof(c));
}
*/
int	deal_key(int key, void *param)
{
	(void)key;
    (void)param;
    ft_putchar_fd('X', 1);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	img.img = mlx_new_image(mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//custom method - white
	my_mlx_pixel_put(&img, 300, 300, 0x00FFFFFF);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	//minilibx method - red
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0x00FF0000);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	
	mlx_loop(mlx_ptr);
	return (0);
}

/*
int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
*/

