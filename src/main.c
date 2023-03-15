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


void	sys_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	t_data	img;
	t_line	line;

	line.x0 = 0;
	line.y0 = 0;
	line.x1 = 250;
	line.y1 = 250;
	line.color = 0x08d86FFF;
	(void) argv;
	if (argc != 2)
		return (0);
	sys_init(&vars);
	img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_key_hook(vars.win, esc_hook, &vars);
	drawline(&line, &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	mlx_loop(vars.mlx);
	return (0);
}