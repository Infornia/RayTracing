/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:19:54 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/08 11:58:57 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				expose_hook(t_data *d)
{
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (1);
}

int				key_hook(int key, t_data *d)
{
	printf("The key pressed %i\n", key);
	if (key == ESC)
		destroy_mlx(d);
	else if (key == DOWN)
		--d->r.o.z;
	else if (key == UP)
		++d->r.o.z;
	else if (key == LEFT)
		--d->r.o.x;
	else if (key == RIGHT)
		++d->r.o.x;
	else if (key == PLUS)
		++d->r.o.y;
	else if (key == MINUS)
		--d->r.o.y;
	draw(d);
	return (1);
}