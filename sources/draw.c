/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:14:15 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/04 20:30:26 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			render(t_data *d)
{
	t_object	o;
	int			i;
	int			j;

	i = 0;
	j = 0;
	// ft_putendl("bonjour");
	o.s = create_sphere(0, 0, 0, 3);
	// ft_putendl("bonjour2");
	o.type = SPHERE;
	o.p = create_plane(0, 1, 0, 0);
	o.type = PLANE;
	while (++j < Y_WIN)
	{
		i = 0;
		while (++i < X_WIN)
			find_closest_intersection(d, &o, i, j);
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