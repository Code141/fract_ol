/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.cl                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:59:33 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/03 18:00:03 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	iterations(double c_r, double c_i, __global t_fractol *fractol, int x, int y, int width, __global *r)
{
	int		i;
	double	z_r;
	double	z_i;
	double	z_r_c;
	double	z_i_c;

	i = 0;
	z_r_c = c_r * c_r;
	z_i_c = c_i * c_i;
	z_i = (c_i + c_i) * c_r  + fractol->ci;
	z_r = z_r_c - z_i_c + fractol->cr;
	i = 0;
	while (z_r_c + z_i_c <= 4 && i < fractol->max_iter)
	{
		z_r_c = z_r * z_r;
		z_i_c = z_i * z_i;
		z_i = (z_i + z_i) * z_r  + fractol->ci;
		z_r = z_r_c - z_i_c + fractol->cr;
r[x + (y * width)] += (z_r_c + z_i_c) * 2;
		i++;
	}


	return (i);
}