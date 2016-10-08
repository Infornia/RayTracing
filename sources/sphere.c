/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:10:59 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/07 17:16:37 by mwilk            ###   ########.fr       */
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

double			hitsphere(t_ray *r, t_sphere *s)
{
	double	a;
	double	b;
	double	c;
	double	t;

	a = vec_dot(&r->vd, &r->vd);
	b = 2 * r->vd.x * (r->o.x - s->p.x);
	b += 2 * r->vd.y * (r->o.y - s->p.y);
	b += 2 * r->vd.z * (r->o.z - s->p.z);
	c = (r->o.x - s->p.x) * (r->o.x - s->p.x);
	c += (r->o.y - s->p.y) * (r->o.y - s->p.y);
	c += (r->o.z - s->p.z) * (r->o.z - s->p.z);
	c -= s->r * s->r;
	t = solve_2nd_deg(a, b ,c);
	return (t);
}
