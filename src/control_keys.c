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

// int esc_hook(int keycode, t_vars *vars)
// {
// 	if (keycode == KEY_ESC)
// 		mlx_destroy_window(vars->mlx, vars->win);
//     else if (keycode == 0)
//         ft_putendl_fd("hello", 1);
//     free(vars->mlx);
//     return (0);
// }

int esc_hook(int keycode, t_vars *vars)
{
    (void) keycode;
    free(vars->mlx);
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
}
