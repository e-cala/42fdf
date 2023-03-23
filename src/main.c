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

/*
1. crear estructura punto 
2. dibujar 8 puntos
3. crear hooks para rotar cubo - rotacion / escala / posicion
*/

// projection matrix
void	sys_init(t_meta *meta)
{
	meta->vars.mlx = mlx_init();
	meta->vars.win = mlx_new_window(meta->vars.mlx,
			WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	meta->img.img = mlx_new_image(meta->vars.mlx,
			WIN_WIDTH, WIN_HEIGHT);
	meta->img.addr = mlx_get_data_addr(meta->img.img,
			&meta->img.bits_per_pixel,
			&meta->img.line_length, &meta->img.endian);
}

void	init_cube(t_meta *meta)
{
	meta->cube.points[0].color = 0x0FF0000; //up-left
	meta->cube.points[0].axis[X] = 150;
	meta->cube.points[0].axis[Y] = 150;
	meta->cube.points[1].color = 0x0FFFFFF;
	meta->cube.points[1].axis[X] = 170;
	meta->cube.points[1].axis[Y] = 150;
	meta->cube.points[2].color = 0x0FFFFFF;
	meta->cube.points[2].axis[X] = 150;
	meta->cube.points[2].axis[Y] = 170;
	meta->cube.points[3].color = 0x008800; //down-right
	meta->cube.points[3].axis[X] = 170;
	meta->cube.points[3].axis[Y] = 170;
	meta->cube.points[4].color = 0x0FF0000;
	meta->cube.points[4].axis[X] = 170;
	meta->cube.points[4].axis[Y] = 130;
	meta->cube.points[5].color = 0x0FFFFFF;
	meta->cube.points[5].axis[X] = 190;
	meta->cube.points[5].axis[Y] = 130;
	meta->cube.points[6].color = 0x0FFFFFF;
	meta->cube.points[6].axis[X] = 170;
	meta->cube.points[6].axis[Y] = 150;
	meta->cube.points[7].color = 0x008800;
	meta->cube.points[7].axis[X] = 190;
	meta->cube.points[7].axis[Y] = 150;
}

void	paint(t_meta *meta)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		my_mlx_pixel_put(&meta->img,
			meta->cube.points[i].axis[X],
			meta->cube.points[i].axis[Y],
			meta->cube.points[i].color);
		mlx_put_image_to_window(&meta->vars.mlx,
			meta->vars.win, meta->img.img,
			meta->cube.points[i].axis[X],
			meta->cube.points[i].axis[Y]);
		i++;
	}
}

int	main(void)
{
	t_meta	meta;

	//meta.line.x0 = 0;
	//meta.line.y0 = 0;
	//meta.line.x1 = 100;
	//meta.line.y1 = 100;
	//meta.line.color = 0x0FFFFFF;
	sys_init(&meta);
	init_cube(&meta);
	paint(&meta);
	drawline2(&meta.cube, &meta.img);
	//drawline(&meta.line, &meta.img);
	mlx_put_image_to_window(meta.vars.mlx,
		meta.vars.win,
		meta.img.img, 0, 0);
	mlx_key_hook(meta.vars.win, esc_hook, &meta.vars);
	mlx_loop(meta.vars.mlx);
	free(meta.vars.mlx);
	return (0);
}