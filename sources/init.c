/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:16:34 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/05 17:52:04 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		init_obj(t_data *d)
{
	d->o = tt_malloc(sizeof(t_object));
	// d->o->obj = create_sphere(0, 0, 0, 3);
	// d->o->type = SPHERE;
	d->o->obj = create_plane(0, 1, 0, 0);
	d->o->type = PLANE;
}

static void				init_cam(t_cam *c)
{
	c->p.x = 0;
	c->p.y = 0;
	c->p.z = 10;
}

t_data			*init(void)
{
	t_data	*d;

	d = tt_malloc(sizeof(t_data));
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, X_WIN, Y_WIN, "RT");
	d->img = mlx_new_image(d->mlx, X_WIN, Y_WIN);
	d->dimg = mlx_get_data_addr(d->img, &d->bpp, &d->size, &d->endian);
	d->bpp /= 8;
	d->max_size = (unsigned int)(d->size * Y_WIN + d->bpp * X_WIN);
	init_cam(&d->c);
	init_obj(d);
	d->fov = tan((20 * M_PI) / 180);
	printf("upleft cood %f, %f, %f\n", d->c.upleft.x, d->c.upleft.y, d->c.upleft.z);
	return (d);
}