/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:50:43 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/04 17:11:40 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <screen/screen.h>
#include <core/core.h>

t_screen	*new_screen(void *mlx, int width, int height)
{
	t_screen *screen;

	screen = (t_screen*)malloc(sizeof(t_screen));
	if (!screen)
		mlxyz_crash("Broken malloc");
	screen->width = width;
	screen->height = height;
	screen->ar = width / height;
	screen->win = mlx_new_window(mlx, width, height, "FdF");
	screen->canevas = new_canevas(mlx, width, height);
	return (screen);
}

t_img		*new_canevas(void *mlx, int width, int height)
{
	t_img	*canevas;
	int		bpp;
	int		size_line;
	int		endian;

	canevas = (t_img*)malloc(sizeof(t_img));
	if (!canevas)
		mlxyz_crash("Broken malloc");
	canevas->width = width;
	canevas->height = height;
	size_line = width;
	canevas->id = mlx_new_image(mlx, canevas->width, canevas->height);
	canevas->data = mlx_get_data_addr(canevas->id, &bpp, &size_line, &endian);
	return (canevas);
}