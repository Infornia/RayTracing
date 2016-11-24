/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:21:38 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/10 18:17:17 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_plane		*create_plane(t_vec3 n, double d)
{
	t_plane		*plane;

	plane = tt_malloc(sizeof(t_plane));
	plane->n = normalize(n);
	plane->d = d;
	plane->p = vec_scalar(plane->n, d);
	printf("%f, %f, %f\n", plane->p.x, plane->p.y, plane->p.z);
	return (plane);
}

t_hitpoint		hitplane(t_ray *r, t_plane *p)
{
	double		t;
	t_hitpoint	h;
	
	h.n = p->n;
	t = -(p->d - vec_dot(h.n, r->o)) / vec_dot(h.n, r->dir);
	if (t < EPSILON)
		return(miss());
	h.t = t;
	h.p = vec_add(r->o, vec_scalar(r->dir, h.t));
	h.c = p->color;
	// h.m = p->m;
	return (h);
}