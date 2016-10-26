/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:14:15 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/26 16:31:34 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3			get_ray_dir(int x, int y)
{
	t_vec3	dir;

	dir.x = ((2 * (x + 0.5) / X_WIN) - 1) * RATIO * FOV;
	dir.y = (1 - (2 * ((0.5 + y) / Y_WIN))) * FOV;
	dir.z = 1;
	dir = normalize(dir);
	return (dir);
}

void			render(t_data *d)
{
	int			x;
	int			y;

	d->r.o = d->cam.p;
	y = Y_WIN;
	while (y--)
	{
		x = X_WIN;
		while (x--)
		{
			d->r.dir = get_ray_dir(x, y);
			d->c = put_col(CBLACK);
			d->h = find_closest_intersection(d->o, &d->r);
			if (d->h.t < MAX_DIST)
				d->c = compute_color(d, &d->h, d->c);
			color_pixel(d, RGB(d->c.r, d->c.g, d->c.b), x, y);
				// color_pixel(d, CWHITE, x, y);
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
	printf("last %zu, now %zu, Delta %f\n", d->time, d->lastime, dframe);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	// printf("x %f, y %f, z %f\n", d->r.o.x, d->r.o.y, d->r.o.z);
	// mlx_do_sync(d->mlx);
}