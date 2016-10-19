/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:19:12 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/19 19:11:31 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_color	diffuse(t_data *d, t_hitpoint *h, t_light *l, t_color c)
{
	double		coef;
	float		angle;
	float		t;
	
	t = 0.0;
	angle = 0.0;
	if (l->type == DIR)
		l->r.dir = l->spotlight;
	else
		l->r.dir = normalize(vec_sub(l->r.o, h->p));
	coef = vec_dot(l->r.dir, h->normalize);
	if (l->type == SPOTLIGHT)
		angle = vec_dot(l->r.dir, l->spotlight);
	if (coef > 0 && angle <= 0)
	{
		if (!find_intersection(d->o, l))
			c = add_col(c, scal_col(l->color, coef));
	}
	else
		coef = 0.0;
	return (c);
}

t_color			compute_color(t_data *d, t_hitpoint *h, t_color c)
{
	t_light		*l;
	
	l = d->l;
	while (l)
	{
		if (l->type == OMNI)
			c = add_col(c, scal_col(l->color, 0.1));
		else if (l->type)
			c = diffuse(d, h, l, c);
			// c = add_col(c, scal_col(0.9, mult_col(diffuse(d, h, l, c), l->color)));
		l = l->next;
	}
	return (moy_col(c));
}