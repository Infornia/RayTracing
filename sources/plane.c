/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:21:38 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/07 17:17:45 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_plane		*create_plane(float vx, float vy, float vz, float d)
{
	t_plane		*plane;
	t_vec3		vd;

	plane = tt_malloc(sizeof(t_plane));
	vd.x = vx;
	vd.y = vy;
	vd.z = vz;
	plane->vd = vd;
	plane->offset = d;
	return (plane);
}

double			hitplane(t_ray *r, t_plane *p)
{
	double		t;

	t = -((p->vd.x * r->o.x + p->vd.y * r->o.y + p->vd.z * r->o.z + p->offset)
		/ (r->vd.x * p->vd.x + r->vd.y * p->vd.y + r->vd.z * p->vd.z));
	return (t);
}
