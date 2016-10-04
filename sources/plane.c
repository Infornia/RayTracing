/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:21:38 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/04 20:21:26 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_plane		create_plane(float vx, float vy, float vz, float d)
{
	t_plane		plane;
	t_vec3		vd;

	vd.x = vx;
	vd.y = vy;
	vd.z = vz;
	plane.vd = vd;
	plane.offset = d;
	
	return (plane);
}

double			hitplane(t_data *d, t_plane *p)
{
	double		t;

	t = -((p->vd.x * d->r.o.x + p->vd.y * d->r.o.y + p->vd.z * d->r.o.z + p->offset)
		/ (d->r.vd.x * p->vd.x + d->r.vd.y * p->vd.y + d->r.vd.z * p->vd.z));
	return (t);
}
