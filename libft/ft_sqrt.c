/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 11:18:17 by gelambin          #+#    #+#             */
/*   Updated: 2017/08/30 13:03:27 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int i;

	i = 0;
	if (nb < 2)
		return (0);
	while ((i * i) < nb)
		i++;
	if ((i * i) == nb)
		return (i);
	return (0);
}