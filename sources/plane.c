/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:21:38 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/26 17:18:08 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_plane		*create_plane(float x, float y, float z, float d)
{
	t_plane		*plane;

	plane = tt_malloc(sizeof(t_plane));
	plane->n = normalize(vec3_new(x, y, z));
	plane->d = d;
	return (plane);
}

t_hitpoint		hitplane(t_ray *r, t_plane *p)
{
	float		t;
	float		num;
	float		denum;
	t_hitpoint	h;
	
	num = vec_dot(p->n, r->o);
	denum = vec_dot(p->n, r->dir) + p->d;
	t = -num / denum;
	if (t < EPSILON)
		return(miss());
	h.t = t;
	h.p = vec_add(r->o, vec_scalar(r->dir, h.t));
	h.n = normalize(p->n);
	h.c = p->color;
	// h.m = p->m;
	return (h);
}
