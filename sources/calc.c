/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:19:12 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/11 19:36:14 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3			get_ray_dir(int x, int y)
{
	t_vec3	dir;

	dir.x = ((-X_HALF + 0.5 + x) / X_WIN) * X_WIN / Y_WIN * FOV;
	dir.y = -((Y_HALF + 0.5 - y) / Y_WIN) * FOV;
	dir.z = 1;
	// dir.x = (2.0f * ((x + 0.5f) / X_WIN) - 1.0) * d->c.fov;
	// dir.y = (1.0f - 2.0f * ((y + 0.5) / Y_WIN)) * d->c.fov;
	// dir.z = 1;
	dir = normalize(dir);
	return (dir);
}

double			solve_2nd_deg(double a, double b, double c)
{
	float	d;
	double	ret1;
	double	ret2;

	d = (b * b) - (4 * a * c);
	// a = 1/4;
	// d = (b * b) - c;
	if (d < 0.0)
		return (0.0);
	if (d != 0.0)
	{
		d = sqrt(d);
		ret1 = (-b - d) / (2 * a);
		ret2 = (-b + d) / (2 * a);
		if (ret2 < ret1)
			return (ret2);
		else
			return (ret1);
	}
	else
		return (-b / (2 * a));
}

void		get_angle_coef(t_hitpoint *h, t_light *l, double *coef)
{
	if (h->o->type == SPHERE)
		h->n = vec_sub(h->p, ((t_sphere *)h->o->obj)->p);
	if (h->o->type == PLANE)
		h->n = vec_sub(h->p, ((t_plane *)h->o->obj)->vd);
	h->normalize = normalize(h->n);
	*coef = vec_dot(l->r.vd, h->normalize);
}

t_color		compute_color(t_data *d, t_hitpoint *h)
{
	// t_ray		r;
	t_light		*l;
	t_color		c;
	float		t;
	double		coef;
	
	t = 0.0;
	coef = 0.0;
	l = d->l;
	c = put_col(0, 0, 0);
	// printf("%i, %i\n", x, y);
	while (l)
	{
		l->r.vd = normalize(vec_sub(l->r.o, h->p));
		find_closest_intersection(d->o, &l->r, &t);
		if (t == 1000.0)
		{
			get_angle_coef(h, l, &coef);
			if (coef > 0)
			{
				c = add_col(c, l->color.r * coef, l->color.g * coef, l->color.b * coef);
			}
		}
		l = l->next;
	}
	return (moy_col(c));
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
		else if (tmp->type == PLANE)
			t = hitplane(r, tmp->obj);
		if (t > EPSILON && t < *tmin)
		{
			*tmin = t;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}