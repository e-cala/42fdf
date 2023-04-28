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
1. Crear estructuras general, punto, vars, s_data, map
2. Drawline
3. Funciion zoom
4. Cargar mapa
5. Crear hooks rotar cubo - rotacion / escala / posicion
*/

// projection matrix
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

int	main(void)
{
	t_meta	meta;
	t_point	start;
	t_point	end;

	sys_init(&meta);
	start.axis[X] = 300;
	start.axis[Y] = 300;
	start.axis[2] = 0;
	start.color = GREEN;
	end.axis[X] = 500;
	end.axis[Y] = 250;
	end.axis[2] = 0;
	end.color = YELLOW;
	plot_line(&meta, start, end);
	

	mlx_put_image_to_window(meta.vars.mlx,
		meta.vars.win,
		meta.data.img, 0, 0);

	mlx_key_hook(meta.vars.win, esc_hook, &meta.vars);
	mlx_loop(meta.vars.mlx);
	free(meta.vars.mlx);
	return (0);
}



















/*
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

void	init_cube(t_meta *meta)
{
	meta->cube.points[0].color = WHITE;	//front-up-left
	meta->cube.points[0].axis[X] = 150;
	meta->cube.points[0].axis[Y] = 150;
	meta->cube.points[1].color = WHITE;	//front-up-right SOLAPA
	meta->cube.points[1].axis[X] = 170;
	meta->cube.points[1].axis[Y] = 150;
	meta->cube.points[2].color = WHITE;	//front-down-left
	meta->cube.points[2].axis[X] = 150;
	meta->cube.points[2].axis[Y] = 170;
	meta->cube.points[3].color = WHITE;	//front-down-right
	meta->cube.points[3].axis[X] = 170;
	meta->cube.points[3].axis[Y] = 170;
	meta->cube.points[4].color = YELLOW; // back-up-left
	meta->cube.points[4].axis[X] = 170;
	meta->cube.points[4].axis[Y] = 130;
	meta->cube.points[5].color = YELLOW; //back-up-right
	meta->cube.points[5].axis[X] = 190;
	meta->cube.points[5].axis[Y] = 130;
	meta->cube.points[6].color = WHITE;	//back-down-left SOLAPA
	meta->cube.points[6].axis[X] = 170;
	meta->cube.points[6].axis[Y] = 150;
	meta->cube.points[7].color = WHITE;	//back-down-right
	meta->cube.points[7].axis[X] = 190;
	meta->cube.points[7].axis[Y] = 150;
}

void	cube_edges(t_meta *meta)
{
	meta->cube.line.x0 = meta->cube.points[0].axis[X];
	meta->cube.line.x1 = meta->cube.points[1].axis[X];
	meta->cube.line.y0 = meta->cube.points[0].axis[Y];
	meta->cube.line.y1 = meta->cube.points[1].axis[Y];
	meta->cube.line.color = GREEN;
}

void	cube_edges2(t_meta *meta)
{
	meta->cube.line.x0 = meta->cube.points[1].axis[X];
	meta->cube.line.x1 = meta->cube.points[2].axis[X];
	meta->cube.line.y0 = meta->cube.points[1].axis[Y];
	meta->cube.line.y1 = meta->cube.points[2].axis[Y];
	meta->cube.line.color = YELLOW;
}

void	cube_edges3(t_meta *meta)
{
	meta->cube.line.x0 = meta->cube.points[2].axis[X];
	meta->cube.line.x1 = meta->cube.points[3].axis[X];
	meta->cube.line.y0 = meta->cube.points[2].axis[Y];
	meta->cube.line.y1 = meta->cube.points[3].axis[Y];
	meta->cube.line.color = WHITE;
}

void	cube_edges4(t_meta *meta)
{
	meta->cube.line.x0 = meta->cube.points[3].axis[X];
	meta->cube.line.x1 = meta->cube.points[4].axis[X];
	meta->cube.line.y0 = meta->cube.points[3].axis[Y];
	meta->cube.line.y1 = meta->cube.points[4].axis[Y];
	meta->cube.line.color = RED;
}

int	main(void)
{
	t_meta	meta;

	sys_init(&meta);
	init_cube(&meta);
	paint(&meta);
	t_line algo;
	algo.x0 =  150;
	algo.x1 = 170;
	algo.y0 = 170;
	algo.y1 = 175;
	algo.color = GREEN;

	drawline(&algo, &meta);
	cube_edges(&meta);
	drawline(&meta.cube.line, &meta.img);
	cube_edges3(&meta);
	drawline(&meta.cube.line, &meta.img);
	mlx_put_image_to_window(meta.vars.mlx,
		meta.vars.win,
		meta.img.img, 0, 0);

	mlx_key_hook(meta.vars.win, esc_hook, &meta.vars);
	mlx_loop(meta.vars.mlx);
	free(meta.vars.mlx);
	return (0);
}
*/