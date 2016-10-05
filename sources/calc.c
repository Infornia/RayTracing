/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:19:12 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/05 17:53:31 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3			get_ray_dir(t_data *d, int x, int y)
{
	t_vec3	dir;

	dir.x = (2.0f * ((x + 0.5f) / X_WIN) - 1.0) * X_WIN / Y_WIN * d->fov;
	dir.y = (1.0f - 2.0f * ((y + 0.5) / Y_WIN)) * d->fov;
	dir.z = -1;
	dir = normalize(dir);
	return (dir);
}

double			solve_2nd_deg(double a, double b, double c)
{
	float	d;
	double	ret;
	double	ret2;

	d = (b * b) - (4 * a * c);
	ret = 0;
	if (d > 0)
	{
		d = sqrt(d);
		ret = (-b - d) / (2 * a);
		ret2 = (-b + d) / (2 * a);
		if (ret2 < ret)
			ret = ret2;
	}
	return (ret);
}

void			find_closest_intersection(t_data *d, t_object *o, int x, int y)
{
	float tmin;
	float t;
	
	d->r.o = d->c.p;
	d->r.vd = get_ray_dir(d, x, y);
	tmin = 1000.0;
	t = 0.0;
	// if (o->type == SPHERE)
		tmin = (t = hitsphere(d,o->obj)) < tmin && t > 0 ? t : tmin;
	if (o->type == PLANE)
		tmin = (t = hitplane(d,o->obj)) < tmin && t > 0 ? t : tmin;
	if (tmin > 0.01 && tmin < 1000)//EPSILON
	{
		if (o->type == SPHERE)
			color_pixel(d, CPINK, x, y);
		else if (o->type == PLANE)
			color_pixel(d, CWHITE, x, y);
	}
	else
		color_pixel(d, CBLACK, x, y);
}