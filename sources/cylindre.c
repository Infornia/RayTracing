/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 13:38:43 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/01 14:09:40 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// t_cone		*create_cyl(double x, double y, double z, double r)
// {
// 	t_cyl		*c;
// 	t_vec3		p;
// 
// 	c = tt_malloc(sizeof(t_cyl));
// 	p.x = x;
// 	p.y = y;
// 	p.z = z;
// 	c->p = p;
// 	c->r = r;
// 	return (c);
// }
// 
// t_hitpoint		hitcyl(t_ray *r, t_cyl *c)
// {
// 	t_hitpoint	h;
// 
// 	h.p = vec_add(r->o, vec_scalar(r->dir, h.t));
// 	h.n = normalize(vec_sub(h.p, s->p));
// 	h.c = c->color;
// 	// h.m = p->m;
// 	return (h);
// }