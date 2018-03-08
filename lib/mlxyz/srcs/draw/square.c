/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:09:27 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/08 20:02:36 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw/square.h>

void	square(t_img *canevas, t_vector2 v1, t_vector2 v2, unsigned int color)
{
	int x;

	x = v1.x;
	while (v1.x < v2.x)
	{
		((unsigned int*)canevas->data)[(v1.y * canevas->width) + v1.x] = color;
		((unsigned int*)canevas->data)[(v2.y * canevas->width) + v1.x] = color;
		v1.x++;
	}
	while (v1.y < v2.y)
	{
		((unsigned int*)canevas->data)[(v1.y * canevas->width) + x] = color;
		((unsigned int*)canevas->data)[(v1.y * canevas->width) + v2.x] = color;
		v1.y++;
	}
}
