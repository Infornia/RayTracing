/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:14:15 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/09 19:00:37 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			render(t_data *d)
{
	t_object	*o;
	int			i;
	int			j;

	j = -1;
	while (++j < Y_WIN)
	{
		i = -1;
		while (++i < X_WIN)
		{
			d->r.o = d->c.p;
			d->r.vd = get_ray_dir(d, i, j);
			o = find_closest_intersection(d->o, &d->r, &d->tmin);
			if (o)
				compute_color(d, o, i, j);
			else
				color_pixel(d, CBLACK, i, j);
		}
	}
}

void			draw(t_data *d)
{
	double	dframe;

	d->lastime = clock();
	render(d);
	d->time = clock();
	dframe = d->time - d->lastime;
	printf("last %zu, now %zu, Delta %f\n", d->time, d->lastime, dframe);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}