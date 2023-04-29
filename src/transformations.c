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

void    zoom(t_point *point, int len)
{   
    int i;

    i = 0;
    while (i < len)
    {
        point->axis[X] *= 2;
        point->axis[Y] *= 2;
        point->axis[Z] *= 2;
        i++;
    }
}
