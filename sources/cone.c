/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 12:17:36 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/08 11:58:46 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cone		*create_cone(t_vec3 p, double r, double h)
{
	t_cone		*c;

	c = tt_malloc(sizeof(t_cone));
	c->p = p;
	c->r = r;
	c->h = h;
	return (c);
}

t_hitpoint		hitcone(t_ray *r, t_cone *c)
{
	t_hitpoint	h;
	t_param		p;
	double		k;
	t_vec3		e;

	e.x = r->o.x - c->p.x;
	e.y = r->o.y - c->p.y;
	e.z = r->o.z - c->p.z;
	
	// k = c->r / c->h;
	// k = k * k;
	k = 1;
	p.a = r->dir.x * r->dir.x + r->dir.z * r->dir.z - r->dir.y * r->dir.y * k;
	p.b = 2 * (r->dir.x * e.x + r->dir.z * e.z - r->dir.y * e.y * k);
	p.c = e.x * e.x + e.z * e.z - e.y * e.y * k;
	if ((p.det = p.b * p.b - 4 * p.a * p.c) < EPSILON)
		return (miss());
	p.det = sqrt(p.det);
	h.t = (-p.b - p.det) / (2 * p.a);
	if (h.t < EPSILON)
		h.t = (-p.b + p.det) / (2 * p.a);
	if (h.t < EPSILON)
		return (miss());
	h.p = vec_add(r->o, vec_scalar(r->dir, h.t));
	h.n = normalize(vec3_new(h.p.x - c->p.x, 0, h.p.z - c->p.z));
	h.c = c->color;
	// h.m = p->m;
	return (h);
}