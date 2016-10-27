/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:21:38 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/27 17:10:08 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_plane		*create_plane(double x, double y, double z, double d)
{
	t_plane		*plane;

	plane = tt_malloc(sizeof(t_plane));
	plane->n = normalize(vec3_new(x, y, z));
	plane->d = d;
	return (plane);
}

t_hitpoint		hitplane(t_ray *r, t_plane *p)
{
	double		t;
	double		num;
	double		denum;
	t_hitpoint	h;
	
	num = vec_dot(p->n, r->o);
	denum = vec_dot(p->n, r->dir) + p->d + EPSILON;
	t = -num / denum;
	if (t < EPSILON)
		return(miss());
	h.t = t;
	h.p.x = r->o.x + r->dir.x * h.t;
	h.p.y = r->o.y + r->dir.y * h.t;
	h.p.z = r->o.z + r->dir.z * h.t;
	h.n = p->n;
	h.c = p->color;
	// h.m = p->m;
	return (h);
}
