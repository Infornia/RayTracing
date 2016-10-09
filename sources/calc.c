/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:19:12 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/09 19:01:15 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3			get_ray_dir(t_data *d, int x, int y)
{
	t_vec3	dir;

	dir.x = (2.0f * ((x + 0.5f) / X_WIN) - 1.0) * X_WIN / Y_WIN * d->fov;
	dir.y = (1.0f - 2.0f * ((y + 0.5) / Y_WIN)) * d->fov;
	dir.z = 1;
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
	if (d > 0.0)
	{
		d = sqrt(d);
		ret = (-b - d) / (2 * a);
		ret2 = (-b + d) / (2 * a);
		if (ret2 < ret)
			ret = ret2;
	}
	else if (d == 0.0)
	{
		ret = -b / (2 * a);
	}
	return (ret);
}

void		get_angle_coef(t_data *d, t_object *o, t_light *l, double *coef)
{
	if (o->type == SPHERE)
	{
		d->h.n = normalize(vec_sub(&((t_sphere *)o->obj)->p, &d->h.p));
		*coef = 1 / vec_dot(&l->r.vd, &d->h.n);
	}
	else if (o->type == PLANE)
		*coef = vec_dot(&l->r.vd, &((t_plane *)o->obj)->vd);
}

void		compute_color(t_data *d, t_object *o, int x, int y)
{
	t_light		*l;
	t_color		c;
	float		t;
	double		coef;
	
	t = 0.0;
	coef = 0.0;
	l = d->l;
	d->h.p = vec_scalar(&d->r.vd, d->tmin);
	c = put_col(o->color.r, o->color.g, o->color.b);
	while (l)
	{
		l->r.vd = normalize(vec_sub(&d->h.p, &l->r.o));
		find_closest_intersection(o, &l->r, &t);
		if (!t)
		{
			get_angle_coef(d, o, l, &coef);
			if (coef > 0)
			{
				add_col(&c, l->color.r * coef, l->color.g * coef, l->color.b * coef);
				moy_col(&c);
				color_pixel(d, RGB(c.r, c.g, c.b), x, y);
			}
			else
				color_pixel(d, CBLACK, x, y);
		
		}
		l = l->next;
	}
		
	
	// if (tmp->type == SPHERE)
		// color_pixel(d, col, x, y);
	// else if (tmp->type == PLANE)
		// color_pixel(d, col, x, y);
}

t_object		*find_closest_intersection(t_object *o, t_ray *r, float *tmin)
{
	t_object	*ret;
	t_object	*tmp;
	float		t;
	
	ret = NULL;
	tmp = o;
	t = 0.0;
	*tmin = 1000.0;
	while (tmp)
	{
		if (tmp->type == SPHERE)
			t = hitsphere(r, tmp->obj);
		if (tmp->type == PLANE)
			t = hitplane(r, tmp->obj);
		if (t > EPSILON && t < *tmin)
		{
			ret = tmp;
			*tmin = t;
		}
		tmp = tmp->next;
	}
	*tmin = t;
	return (ret);
}