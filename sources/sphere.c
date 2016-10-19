/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:10:59 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/19 19:50:51 by mwilk            ###   ########.fr       */
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

float			hitsphere(t_ray *r, t_sphere *s)
{
	t_vec3	e;
	float	a;
	float	b;
	float	t;

	e = vec_sub(s->p, r->o);
	a = vec_dot(e, r->dir);
	b = s->r * s->r - vec_dot(e, e) + a * a;
	t = MAX_DIST;
	if (b >= 0.0)
		t =  MIN(a - sqrtf(b), a + sqrtf(b));
	return (t);
}
