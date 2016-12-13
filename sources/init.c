/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:16:34 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/16 16:52:25 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		init_light(t_data *d)
{
	t_light		*l;

	l = add_light(NULL, VEC3(0, 0, 0), VEC3(0, 0, 0), RGB(50,50,50));
	d->l = l;
	l->type = OMNI;

	l = add_light(l, VEC3(3, 1, 10), VEC3(0, 0, 0), CRED);
	l->type = SPOT;

	l = add_light(l, VEC3(-3, -1, 10), VEC3(0, 0, 0), CBLUE);
	l->type = SPOT;

	l = add_light(l, VEC3(-MAX_DIST, 0, 0), VEC3(1, 0, 0), CBLUE);
	l->type = DIR;

	l = add_light(l, VEC3(5, 1, 10), VEC3(0, 0, 1), CGREEN);
	l->type = SPOTLIGHT;
}

static void		init_obj(t_data *d)
{
	t_object	*o;

	d->o = NULL;
	o = add_object(d->o, SPHERE, VEC3(-1, 0, 10), 0.5);
	((t_sphere*)o->obj)->color = put_col(CWHITE);
	d->o = o;

	o = add_object(d->o, SPHERE, VEC3(1, 0, 10), 1);
	((t_sphere*)o->obj)->color = put_col(CWHITE);

	o = add_object(d->o, PLANE, VEC3(0, 1, 0), 2);
	((t_plane*)o->obj)->color = put_col(CWHITE);

	o = add_object(d->o, CONE, VEC3(0, 0, 0), 1);
	((t_cone*)o->obj)->color = put_col(CWHITE);
}

t_data			*init(void)
{
	t_data		*d;

	if(!(d = tt_malloc(sizeof(t_data))))
		exit(tt_pl("Failed to alloc data"));
	d->r.o = VEC3(0, 0, 0);
	tt_pl("Init mlx");
	init_mlx(d);
	tt_pl("Init obj");
	init_obj(d);
	tt_pl("Init light");
	init_light(d);
	return (d);
}
