/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:14:15 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/16 19:13:04 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3			get_ray_dir(int x, int y)
{
	t_vec3	dir;

	dir.x = ((-X_HALF + 0.5 + x) / X_WIN) * X_WIN / Y_WIN * FOV;
	dir.y = ((Y_HALF - 0.5 - y) / Y_WIN) * FOV;
	dir.z = 1;
	dir = normalize(dir);
	return (dir);
}

void			render(t_data *d)
{
	t_hitpoint	h;
	t_color		c;
	int			x;
	int			y;

	d->r.o = d->c.p;
	y = -1;
	while (++y < Y_WIN)
	{
		x = -1;
		while (++x < X_WIN)
		{
			c = put_col(0, 0, 0);
			d->r.dir = get_ray_dir(x, y);
			h = find_closest_intersection(d->o, &d->r);
			if (h.o)
			{
				// printf("INTERSECTION %i,%i: t = %f\n", x, y, h.tmin);
				h.p = vec_add(d->r.o, vec_scalar(d->r.dir, h.tmin));
				c = compute_color(d, h, c);
			}
			color_pixel(d, RGB(c.r, c.g, c.b), x, y);
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
	// printf("x %f, y %f, z %f\n", d->r.o.x, d->r.o.y, d->r.o.z);
	// mlx_do_sync(d->mlx);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}