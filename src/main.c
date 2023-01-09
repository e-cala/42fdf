/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:38:21 by ecabanas          #+#    #+#             */
/*   Updated: 2023/01/09 11:57:25 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
