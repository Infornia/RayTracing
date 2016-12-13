/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/08 11:58:58 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			destroy_mlx(t_data *d)
{
	if (d->img)
		mlx_destroy_image(d->mlx, d->img);
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
	{
		free(d->mlx);
		exit(0);
	}
}

void			init_mlx(t_data *d)
{
	d->mlx = mlx_init();
	if(!(d->win = mlx_new_window(d->mlx, X_WIN, Y_WIN, "RT")))
		exit(tt_pl("window open failed"));
	if(!(d->img = mlx_new_image(d->mlx, X_WIN, Y_WIN)))
		exit(tt_pl("image creation failed"));
	if(!(d->dimg = mlx_get_data_addr(d->img, &d->bpp, &d->size, &d->endian)))
		exit(tt_pl("Get image data failed"));
	d->bpp /= 8;
	d->max_size = (unsigned int)(d->size * Y_WIN);
}
