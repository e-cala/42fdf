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

/*          MATRIX          */
#include <math.h>
#include <stdio.h>

t_point	mat_mul(float matrix [3][3], t_point point)
{
	t_point	result;
	int		i;
	int		k;

	i = 0;
    k = 0;
	while (i < 3)
	{
		result.axis[i] = 0;
		k = 0;
		while (k < 3)
		{
			result.axis[i] += matrix[i][k] * point.axis[k];
			k++;
		}
		i++;
	}
	result.color = point.color;
	return (result);
}

void    matrix_zero(float matrix[3][3])
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 3)
    {
        j = 0;
        while (j < 3)
        {
            matrix[i][j] = 0;
            j++;
        }
        i++;
    }
}

void    rotation_x(int len, t_point *points, t_point *projected, int ang)
{
    float   rotation_matrix[3][3];
    float   rad;
    int     i;

    i = 0;
    rad = ang * M_PI / 180;
    matrix_zero(rotation_matrix);
    rotation_matrix[0][0] = 1;
    rotation_matrix[1][1] = cos(rad);
    rotation_matrix[1][2] = -sin(rad);
    rotation_matrix[2][1] = sin(rad);
    rotation_matrix[2][2] = cos(rad);
    while (i < len)
    {
        projected[i] = mat_mul(rotation_matrix, points[i]);
        i++;
    }
}

void	rotation_y(int len, t_point *points, t_point *projected, int ang)
{
	float	rotation_matrix[3][3];
	float	rad;
	int		i;

	i = 0;
	rad = ang * M_PI / 180;
	matrix_zero (rotation_matrix);
	rotation_matrix[0][0] = cos(rad);
	rotation_matrix[0][2] = sin(rad);
	rotation_matrix[1][1] = 1;
	rotation_matrix[2][0] = -sin(rad);
	rotation_matrix[2][2] = cos(rad);
	while (i < len)
	{
		projected[i] = mat_mul(rotation_matrix, points[i]);
		i++;
	}
}

//Funcion que rota los puntos en el eje Z

void	rotation_z(int len, t_point *points, t_point *projected, int ang)
{
	float	rotation_matrix[3][3];
	float	rad;
	int		i;

	i = 0;
	rad = ang * M_PI / 180;
	matrix_zero (rotation_matrix);
	rotation_matrix[0][0] = cos(rad);
	rotation_matrix[0][1] = -sin(rad);
	rotation_matrix[1][0] = sin(rad);
	rotation_matrix[1][1] = cos(rad);
	rotation_matrix[2][2] = 1;
	while (i < len)
	{
		projected[i] = mat_mul(rotation_matrix, points[i]);
		i++;
	}
}
