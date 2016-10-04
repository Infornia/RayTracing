/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:10:59 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/04 20:09:39 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_sphere		create_sphere(int x, int y, int z, int r)
{
	t_sphere	s;
	t_vec3		p;

	p.x = x;
	p.y = y;
	p.z = z;
	s.p = p;
	s.r = r;
	return (s);
}

double			hitsphere(t_data *d, t_sphere *s)
{
	double	a;
	double	b;
	double	c;
	double	t;

	a = vecdot(&d->r.vd, &d->r.vd);
	b = 2 * d->r.vd.x * (d->r.o.x - s->p.x);
	b += 2 * d->r.vd.y * (d->r.o.y - s->p.y);
	b += 2 * d->r.vd.z * (d->r.o.z - s->p.z);
	c = (d->r.o.x - s->p.x) * (d->r.o.x - s->p.x);
	c += (d->r.o.y - s->p.y) * (d->r.o.y - s->p.y);
	c += (d->r.o.z - s->p.z) * (d->r.o.z - s->p.z);
	c -= s->r * s->r;
	t = solve_2nd_deg(a, b ,c);
	return (t);
}
