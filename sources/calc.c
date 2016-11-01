/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:19:12 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/01 17:59:32 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// static t_color	radiance();

static t_color	diffuse(t_data *d, t_hitpoint *h, t_light *l, t_color c)
{
	double		coef;
	double		angle;
	t_ray		r;
	
	angle = 1.0;
	r.o = h->p;
	r.dir = normalize(vec_sub(r.o, l->r.o));
	if (l->type == SPOTLIGHT)
	{
		angle = vec_dot(r.dir, l->spotlight);
		r.dir = vec_scalar(r.dir, angle);
	}
	r.dir = vec_neg(r.dir);
	coef = vec_dot(r.dir, h->n);
	if (coef > 0)
	{
		if (!find_intersection(d->o, r))
			c = add_col(c, scal_col(add_col(l->color, h->c), coef * angle));
	}
	return (c);
}

t_color			compute_color(t_data *d, t_hitpoint *h, t_color c)
{
	t_light		*l;
	
	l = d->l;
	while (l)
	{
		if (l->type == OMNI)
			c = add_col(c, scal_col(add_col(l->color, h->c), 0.1));
		else if (l->type)
			c = diffuse(d, h, l, c);
			// c = add_col(c, scal_col(0.9, mult_col(diffuse(d, h, l, c), l->color)));
		l = l->next;
	}
	return (moy_col(c));
}