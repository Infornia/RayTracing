/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:14:15 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/11 19:08:14 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			render(t_data *d)
{
	t_hitpoint	h;
	t_color		c;
	int			x;
	int			y;

	y = -1;
	d->r.o = d->c.p;
	while (++y < Y_WIN)
	{
		x = -1;
		while (++x < X_WIN)
		{
			d->r.vd = get_ray_dir(x, y);
			h.o = find_closest_intersection(d->o, &d->r, &d->tmin);
			if (h.o)
			{
				h.p = vec_add(d->r.o, vec_scalar(d->r.vd, d->tmin));
				c = compute_color(d, &h);
				color_pixel(d, RGB(c.r, c.g, c.b), x, y);
			}
			else
				color_pixel(d, CBLACK, x, y);
			
		}
	}
}

void			draw(t_data *d)
{
	double	dframe;

	ft_bzero(d->dimg, d->max_size);
	d->lastime = clock();
	render(d);
	d->time = clock();
	dframe = d->time - d->lastime;
	// printf("last %zu, now %zu, Delta %f\n", d->time, d->lastime, dframe);
	// printf("x %f, y %f, z %f\n", d->r.o.x, d->r.o.y, d->r.o.z);
	// mlx_do_sync(d->mlx);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}