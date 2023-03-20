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
#include "../includes/defines.h"

// load map
// draw map
// hooks
//free ptrs
/*
1. crear estructura punto 
2. dibujar 8 puntos
3. crear hooks para rotar cubo - rotacion / escala / posicion
*/

void	sys_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
}

/*
int	main(void)
{
	t_vars	vars;
	t_data	img;
	t_line	line;

	line.x0 = 100;
	line.y0 = 100;
	line.x1 = 250;
	line.y1 = 250;
	line.color = 0x08d86FFF;

	sys_init(&vars);
	img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_key_hook(vars.win, esc_hook, &vars);
	//drawline(&line, &img);
	my_mlx_pixel_put(img.img, line.x0, line.y0, line.color);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, line.x0, line.y0);
	my_mlx_pixel_put(img.img, line.x1, line.y1, line.color);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, line.x1, line.y1);

	mlx_loop(vars.mlx);
	return (0);
}*/

int	main(void)
{
	t_vars	vars;
	t_data img;
	t_point	point;

	point.x = 250;
	point.y = 250;
	point.color = 0x0FFFFFF;
	sys_init(&vars);
	img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(img.img, point.x, point.y, point.color);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, point.x, point.y);
	mlx_key_hook(vars.win, esc_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}