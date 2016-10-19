/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:21:38 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/19 18:10:30 by mwilk            ###   ########.fr       */
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

float		hitplane(t_ray *r, t_plane *p)
{
	float	t;
	float	num;
	float	denum;
	
	num = p->d - vec_dot(p->n, r->o);
	denum = vec_dot(p->n, r->dir);
	t = num / denum; 
	if (t < EPSILON)
		t = MAX_DIST;
	return (t);
}
