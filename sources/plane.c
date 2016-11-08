/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:21:38 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/08 11:58:39 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_plane		*create_plane(t_vec3 n, double d)
{
	t_plane		*plane;

	plane = tt_malloc(sizeof(t_plane));
	plane->n = normalize(n);
	plane->d = d;
	return (plane);
}

t_hitpoint		hitplane(t_ray *r, t_plane *p)
{
	double		t;
	double		num;
	double		denum;
	t_hitpoint	h;
	
	num = p->d + vec_dot(p->n, r->o);
	denum = vec_dot(p->n, r->dir);
	t = -num / denum;
	if (t < EPSILON)
		return(miss());
	h.t = t;
	h.p = vec_add(r->o, vec_scalar(r->dir, h.t));
	h.n = p->n;
	h.c = p->color;
	// h.m = p->m;
	return (h);
}