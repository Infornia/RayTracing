/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:16:34 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/27 19:28:47 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		init_light(t_data *d)
{
	t_light		*l;
	
	l = add_light(NULL, 0, 0, 0);
	d->l = l;
	l->type = OMNI;
	l->color = put_col(CWHITE);
	l->radius = MAX_DIST;
	
	l = add_light(l, 3, 1, 10);
	l->type = SPOT;
	l->color = put_col(CRED);
	l->radius = MAX_DIST;
	
	l = add_light(l, -MAX_DIST, 0, -MAX_DIST);
	l->type = DIR;
	l->color = put_col(CBLUE);
	// l->r.dir = normalize(vec3_new(1, 0, 1));
	l->radius = MAX_DIST + 1;

	l = add_light(l, -10, 0, 0);
	l->type = SPOTLIGHT;
	l->color = put_col(CGREEN);
	l->spotlight = normalize(vec3_new(0, 0, 1));
	l->radius = 20;
}

static void		init_obj(t_data *d)
{
	t_object	*o;
	
	d->o = NULL;
	o = add_object(d->o, SPHERE, -1, 0, 10, 1);
	o->color = put_col(CBLUE);
	d->o = o;	
	
	o = add_object(d->o, SPHERE, 1, 0, 10, 1);
	o->color = put_col(CRED);
	
	o = add_object(d->o, PLANE, 0, 1, 0, 0);
	o->color = put_col(CWHITE);
	
	// o = add_object(d->o, PLANE, 0, 0, 0, 0);
	// o->color = put_col(CWHITE);
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