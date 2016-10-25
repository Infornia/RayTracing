/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:19:54 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/25 15:36:55 by mwilk            ###   ########.fr       */
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
		--d->cam.p.z;
	else if (key == UP)
		++d->cam.p.z;
	else if (key == LEFT)
		--d->cam.p.x;
	else if (key == RIGHT)
		++d->cam.p.x;
	else if (key == PLUS)
		++d->cam.p.y;
	else if (key == MINUS)
		--d->cam.p.y;
	draw(d);
	return (1);
}