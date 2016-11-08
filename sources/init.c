/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:16:34 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/08 11:58:54 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		init_light(t_data *d)
{
	t_light		*l;
	
	l = add_light(NULL, vec3_new(0, 0, 0), vec3_new(0, 0, 0), CWHITE);
	d->l = l;
	l->type = OMNI;
	
	l = add_light(l, vec3_new(5, 1, 10), vec3_new(1, 0, 1), CRED);
	l->type = SPOT;
	
	l = add_light(l, vec3_new(-MAX_DIST, 0, 0), vec3_new(1, 0, 0), CBLUE);
	l->type = DIR;
	
	// l = add_light(l, vec3_new(5, 1, 10), vec3_new(0, 0, 1), CGREEN);
	// l->type = SPOTLIGHT;
}

static void		init_obj(t_data *d)
{
	t_object	*o;
	
	d->o = NULL;
	o = add_object(d->o, SPHERE, vec3_new(-1, 0, 10), 0.5);
	((t_sphere*)o->obj)->color = put_col(CRED);
	
	o = add_object(d->o, SPHERE, vec3_new(1, 0, 10), 1);
	((t_sphere*)o->obj)->color = put_col(CRED);
	
	o = add_object(d->o, PLANE, vec3_new(0, 1, 0), 2);
	d->o = o;	
	((t_plane*)o->obj)->color = put_col(CGREEN);
	
	o = add_object(d->o, CONE, vec3_new(1, 1, 10), 1);
	((t_cone*)o->obj)->color = put_col(CBLUE);
}

t_data			*init(void)
{
	t_data		*d;

	d = tt_malloc(sizeof(t_data));
	d->r.o = vec3_new(0, 0, 0);
	init_mlx(d);
	init_obj(d);
	init_light(d);
	// printf("upleft cood %f, %f, %f\n", d->c.upleft.x, d->c.upleft.y, d->c.upleft.z);
	return (d);
}