/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:19:12 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/05 19:16:56 by mwilk            ###   ########.fr       */
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
	float		t;
	float		tmin;
	int			i;
	t_object	*ret;
	t_object	*tmp;
	
	d->r.o = d->c.p;
	d->r.vd = get_ray_dir(d, x, y);
	t = 0.0;
	ret = o;
	tmp = o->next;
	tmin = 1000.0;
	i = 0;
	while (++i < d->nb_obj)
	{
		if (tmp->type == SPHERE)
			t = hitsphere(d,tmp->obj);
		if (tmp->type == PLANE)
			t = hitplane(d,tmp->obj);
		if (t < tmin)
		{
			ret = tmp;
			tmin = t;
		}
		tmp = tmp->next;
	}
	// return (ret);
	if (tmin > 0.01 && tmin < 1000)//EPSILON
	{
		if (ret->type == SPHERE)
			color_pixel(d, CPINK, x, y);
		else if (ret->type == PLANE)
			color_pixel(d, CWHITE, x, y);
	}
	else
		color_pixel(d, CBLACK, x, y);
}