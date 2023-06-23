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
#include "../includes/fdf.h"
#include "../lib/libft/libft.h"
#include "../includes/gnl.h"
#include "../includes/errors.h"

/*
TODO: 
3. Funciion zoom
6. Al clicar la X se cierre
7. Los puntos negativos también se visualizen
*/

void	sys_init(t_meta *meta)
{
	meta->vars.mlx = mlx_init();
	meta->vars.win = mlx_new_window(meta->vars.mlx,
			WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	meta->data.img = mlx_new_image(meta->vars.mlx,
			WIN_WIDTH, WIN_HEIGHT);
	meta->data.addr = mlx_get_data_addr(meta->data.img,
			&meta->data.bits_per_pixel,
			&meta->data.line_length, &meta->data.endian);
}

void	print_map(t_meta meta)
{
	printf("\n");
	printf("total_size:		%i\n", meta.map.total_size);
	printf("length:			%i\n", meta.map.len);
	printf("limits[X]:		%i\n", meta.map.limits.axis[X]);
	printf("limits[Y]:		%i\n", meta.map.limits.axis[Y]);
	for(int m = 0; m < meta.map.total_size; m++)
	{
		if (m % meta.map.limits.axis[X] == 0)
			printf("\n");
		printf("{%i %3i %3i} ", 
		meta.map.points[m].axis[X] + WIN_WIDTH / 2,
		meta.map.points[m].axis[Y] + WIN_HEIGHT / 2,
		meta.map.points[m].axis[Z]);
	}
	printf("\n");
}



/****************************/



int	main(int argc, char *argv[])
{
	t_meta	meta;

	if (argc != 2)
		err(ERR_ARGS);
	read_file(argv[argc - 1], &meta.map);
	print_map(meta);
	sys_init(&meta);
	draw_map(&meta);
	mlx_key_hook(meta.vars.win, key_press, &meta.vars);
	mlx_mouse_hook(meta.vars.win, ft_mouse_down, &meta.vars);
	mlx_loop(meta.vars.mlx);
	return (0);
}