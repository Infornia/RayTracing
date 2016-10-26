/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:10:59 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/26 17:18:04 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_sphere		*create_sphere(int x, int y, int z, int r)
{
	t_sphere	*s;
	t_vec3		p;

	s = tt_malloc(sizeof(t_sphere));
	p.x = x;
	p.y = y;
	p.z = z;
	s->p = p;
	s->r = r;
	return (s);
}

t_hitpoint		hitsphere(t_ray *r, t_sphere *s)
{
	t_vec3		e;
	t_hitpoint	h;
	float		l;
	float		det;

	e = vec_sub(s->p, r->o);
	l = vec_dot(r->dir, e);
	det = l * l - vec_dot(e, e) + s->r * s->r;
	if (det < 0.0)
		return (miss());
	h.t = l - sqrt(det);
	if (h.t < EPSILON)
		h.t = l + sqrt(det);
	if (h.t < EPSILON)
		return (miss());
	e = vec_sub(r->o, s->p);
	h.p = vec_add(r->o, vec_scalar(r->dir, h.t));
	h.n = vec_scalar(vec_sub(h.p, s->p), 1 / s->r);
	h.c = s->color;
	// h.m = p->m;
	return (h);
}
