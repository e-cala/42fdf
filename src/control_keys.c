/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:03:09 by ecabanas          #+#    #+#             */
/*   Updated: 2023/03/15 17:03:12 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx_macos/mlx.h"
#include "../lib/libft/libft.h"
#include "../includes/fdf.h"
#include "../includes/defines.h"
#include "../includes/keycodes.h"

int key_press(int keycode, t_meta *meta)
{
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(meta->vars.mlx, meta->vars.win);
        exit (0);
    }
    if (keycode == KEY_Z)
    {
        meta->map.points[0].axis[X] += 10;
        meta->map.divisor += 1;
    }
    draw_map(meta);
    return (0);
}

