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

int	main(int argc, char *argv[])
{
	//t_meta	meta;
	
	int	fd;
	int	i;
	char *line;

	(void) argc;
	fd = open(argv[1], O_RDONLY);
	line = "";
	i = 0;
	while (i < 20)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		i++;
	}
	fd = close(fd);
	/*sys_init(&meta);
	mlx_put_image_to_window(meta.vars.mlx,
		meta.vars.win,

		meta.data.img, 0, 0);
	mlx_key_hook(meta.vars.win, esc_hook, &meta.vars);
	mlx_loop(meta.vars.mlx);
	free(meta.vars.mlx);*/
	return (0);
}