/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:14:15 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/04 17:16:17 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			render(t_data *d)
{
	t_sphere	s;
	int			i;
	int			j;

	i = 0;
	j = 0;
	printf("I and J %i, %i\n", i, j);
	while (++j < Y_WIN)
	{
		i = 0;
		while (++i < X_WIN)
		{
			s = create_sphere(0, 0, 0, 1);
			find_closest_intersection(d, &s, i, j);
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