/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:10:59 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/10 14:22:43 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_sphere		*create_sphere(t_vec3 p, double r)
{
	t_sphere	*s;

	s = tt_malloc(sizeof(t_sphere));
	s->p = p;
	s->r = r;
	s->r_square = r * r;
	return (s);
}

t_hitpoint		hitsphere(t_ray *r, t_sphere *s)
{
	t_vec3		e;
	t_hitpoint	h;
	double		l;
	double		det;

	e = vec_sub(s->p, r->o);
	l = vec_dot(r->dir, e);
	det = l * l - vec_dot(e, e) + s->r_square;
	if (det <= 0.0)
		return (miss());
	det = sqrt(det);
	h.t = l - det;
	if (h.t < EPSILON)
		h.t = l + det;
	if (h.t < EPSILON)
		return (miss());
	h.p = vec_add(r->o, vec_scalar(r->dir, h.t));
	h.n = normalize(vec_sub(h.p, s->p));
	h.c = s->color;
	// h.m = p->m;
	return (h);
}
