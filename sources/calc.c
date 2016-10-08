/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:19:12 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/08 16:45:16 by mwilk            ###   ########.fr       */
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

void		compute_color(t_data *d, t_object *o, int x, int y)
{
	double		t;
	double		coef;
	t_color		c;
	t_vec3		hitpoint;
	t_ray		light;
	t_object	*tmp;
	
	put_col(&c, RGB(o->color.r, o->color.g, o->color.b));
	hitpoint = vec_scalar(&d->r.vd, d->tmin);
	light.o.x = 10;
	light.o.y = 0;
	light.o.z = 0;
	light.vd = normalize(vec_sub(&hitpoint, &light.o));
	coef = vec_dot(&light.vd, &d->r.vd);
	tmp = o;
	if (tmp->type == SPHERE)
		t = hitsphere(&light,tmp->obj);
	if (tmp->type == PLANE)
		t = hitplane(&light,tmp->obj);
	if (!t && coef > 0)
	{
		put_col(&c, RGB(c.r * coef, c.g * coef, c.b * coef));
		color_pixel(d, RGB(c.r, c.g, c.b), x, y);
	}
		
	
	// if (tmp->type == SPHERE)
		// color_pixel(d, col, x, y);
	// else if (tmp->type == PLANE)
		// color_pixel(d, col, x, y);
}

t_object		*find_closest_intersection(t_data *d, t_object *o)
{
	float		t;
	int			i;
	t_object	*ret;
	t_object	*tmp;
	
	t = 0.0;
	ret = NULL;
	tmp = o;
	d->tmin = 1000.0;
	i = -1;
	while (tmp)
	{
		if (tmp->type == SPHERE)
			t = hitsphere(&d->r, tmp->obj);
		if (tmp->type == PLANE)
			t = hitplane(&d->r, tmp->obj);
		if (t > EPSILON && t < d->tmin)
		{
			ret = tmp;
			d->tmin = t;
		}
		tmp = tmp->next;
	}
	d->tmin = t;
	return (ret);
}