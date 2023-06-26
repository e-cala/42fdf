/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:03:09 by ecabanas          #+#    #+#             */
/*   Updated: 2023/06/26 09:21:58 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx_macos/mlx.h"
#include "../lib/libft/libft.h"
#include "../includes/fdf.h"
#include "../includes/defines.h"
#include "../includes/keycodes.h"

static void	key_press_1(int keycode, t_meta *meta)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(meta->vars.mlx, meta->vars.win);
		exit (0);
	}
	if (keycode == KEY_UP)
	{
		meta->map.ang[X] += 10;
		meta->map.ang[Y] += 10;
	}
	if (keycode == KEY_DOWN)
	{
		meta->map.ang[X] -= 10;
		meta->map.ang[Y] -= 10;
	}
	if (keycode == KEY_RIGHT)
		meta->map.ang[Y] += 10;
	if (keycode == KEY_LEFT)
		meta->map.ang[Y] -= 10;
}

static void	key_press_2(int keycode, t_meta *meta)
{
	if (keycode == KEY_I)
	{
		meta->map.ang[X] = 30;
		meta->map.ang[Y] = 330;
		meta->map.ang[Z] = 30;
	}
	if (keycode == KEY_Z)
		meta->map.divisor += 1;
	if (keycode == KEY_X)
	{
		if (meta->map.divisor > 1)
			meta->map.divisor -= 1;
	}
}

int	key_press(int keycode, t_meta *meta)
{
	key_press_1(keycode, meta);
	key_press_2(keycode, meta);
	draw_map(meta);
	return (0);
}

int	ft_mouse_down(int mousecode, int x, int y, t_meta *meta)
{
	if (mousecode == 1)
	{
		meta->mouse.left_click = 1;
		meta->mouse.prev_click_l.axis[X] = x;
		meta->mouse.prev_click_l.axis[Y] = y;
		draw_map(meta);
	}
	if (mousecode == 4)
		meta->map.scale *= 1.5;
	if (mousecode == 5)
		meta->map.scale /= 1.5;
	draw_map(meta);
	return (0);
}
