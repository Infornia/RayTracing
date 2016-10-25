/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:16:34 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/25 18:00:19 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		init_light(t_data *d)
{
	t_light		*l;
	
	l = create_light(NULL, 0, 0, 0);
	d->l = l;
	l->type = DIR;
	l->color = put_col(R_COL(CWHITE), G_COL(CWHITE), B_COL(CWHITE));
	l->r.dir = normalize(vec3_new(1, 0, 0));
	l->radius = 20;

	// l = create_light(l, -5, 0, 10);
	// l->type = SPOT;
	// l->color = put_col(R_COL(CBLUE), G_COL(CBLUE), B_COL(CBLUE));
	// l->r.dir = vec3_new(0, 0, 0);
	// l->radius = 20;
// 	
// 	l = create_light(l, 0, 0, 0);
// 	l->type = OMNI;
// 	l->color = put_col(255, 255, 255);
// 	l->radius = 20;
// 
	// l = create_light(l, 2, 0, 0);
	// l->type = SPOTLIGHT;
	// l->color = put_col(0, 255, 0);
	// l->spotlight = vec3_new(-1, 0, 0);
	// l->radius = 20;
}

static void		init_obj(t_data *d)
{
	t_object	*o;
	
	d->o = NULL;
	o = add_object(d->o, SPHERE, -1, 0, 10, 1);
	o->color = put_col(R_COL(CBLUE), G_COL(CBLUE), B_COL(CBLUE));
	d->o = o;	
	
	o = add_object(d->o, SPHERE, 1, 0, 10, 1);
	o->color = put_col(R_COL(CRED), G_COL(CRED), B_COL(CRED));
	
	// o = add_object(d->o);
	// o->obj = create_plane(1, 0, 0, 0);
	// o->type = PLANE;
	// o->color = put_col(R_COL(CWHITE), G_COL(CWHITE), B_COL(CWHITE));
	// o->intersection = &hitplane;
	
	o = add_object(d->o, PLANE, 0, 1, 0, 0);
	o->color = put_col(R_COL(CWHITE), G_COL(CWHITE), B_COL(CWHITE));
}

static void				init_cam(t_cam *c)
{
	c->p = vec3_new(0, 0, 0);
	c->vd = vec3_new(0, 0, 0);
	c->w = 0.5;
	c->h = 0.35;
	c->f = 1.0;
	c->fov = tan((30 * M_PI) / 180);
}

t_data			*init(void)
{
	t_data		*d;

	d = tt_malloc(sizeof(t_data));
	init_mlx(d);
	init_cam(&d->cam);
	init_obj(d);
	init_light(d);
	// printf("upleft cood %f, %f, %f\n", d->c.upleft.x, d->c.upleft.y, d->c.upleft.z);
	return (d);
}