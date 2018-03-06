/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 08:00:38 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/06 18:42:54 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCT_H
# include <math.h>
#endif
#include <fractol_struct.h>
#define ABS(value) (((value) < 0) ? -((value)) : (value))

void	burning_ship(t_pixel *pixel)
{
	double z_r;
	double z_i;
	double z_r_c;
	double z_i_c;

	pixel->value = 0;
	pixel->iterations = 0;
	z_r = 0;
	z_i = 0;
	z_r_c = 0;
	z_i_c = 0;
	while (z_r_c + z_i_c <= 4 && pixel->iterations < pixel->max_iter)
	{
		z_r_c = z_r * z_r;
		z_i_c = z_i * z_i;
		z_i = ABS(2 * z_r * z_i + pixel->ci);
		z_r = ABS(z_r_c - z_i_c + pixel->cr);
		pixel->value += (z_r_c + z_i_c);
		pixel->iterations++;
	}
}
