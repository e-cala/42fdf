/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:07:53 by ecabanas          #+#    #+#             */
/*   Updated: 2023/04/29 09:07:57 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/defines.h"

void    zoom(t_point *point, int len, float scale)
{   
    int i;

    i = 0;
    while (i < len)
    {
        point->axis[X] *= scale;
        point->axis[Y] *= scale;
        point->axis[Z] *= scale;
        i++;
    }
}

void    ft_reduce_z(int len, t_point *points, float divisor)
{
    int i;

    i = 0;
    while (i < len)
    {
        points[i].axis[Z] /= divisor;
        i++;
    }
}
