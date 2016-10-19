/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:16:34 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/19 18:44:43 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		init_light(t_data *d)
{
	t_light		*tmp;
	
	tmp = create_light(NULL, 0, 0, 0);
	d->l = tmp;
	tmp->type = DIR;
	tmp->color = put_col(R_COL(CWHITE), G_COL(CWHITE), B_COL(CWHITE));
	tmp->spotlight = normalize(vec3_new(0, -1, 0));
	tmp->radius = 20;

	tmp = create_light(tmp, -10, 0, 10);
	tmp->type = SPOT;
	tmp->color = put_col(R_COL(CBLUE), G_COL(CBLUE), B_COL(CBLUE));
	tmp->r.dir = vec3_new(0, 0, 1);
	tmp->radius = 20;
	
	tmp = create_light(tmp, 0, 0, 0);
	tmp->type = OMNI;
	tmp->color = put_col(255, 255, 255);
	tmp->radius = 20;

	tmp = create_light(tmp, 0, 0, 0);
	tmp->type = SPOTLIGHT;
	tmp->color = put_col(0, 255, 0);
	tmp->spotlight = normalize(vec3_new(0, 0, 1));
	tmp->radius = 20;
}

static void		init_obj(t_data *d)
{
	t_object	*tmp;
	
	tmp = add_object(NULL);
	d->o = tmp;
	tmp->type = SPHERE;
	tmp->obj = create_sphere(-2, 0, 10, 1);
	tmp->color = put_col(R_COL(CBLUE), G_COL(CBLUE), B_COL(CBLUE));
	
	tmp = add_object(d->o);
	tmp->obj = create_sphere(2, 0, 10, 1);
	tmp->type = SPHERE;
	tmp->color = put_col(R_COL(CRED), G_COL(CRED), B_COL(CRED));
	
	tmp = add_object(d->o);
	tmp->obj = create_plane(1, 0, 0, 0);
	tmp->type = PLANE;
	tmp->color = put_col(R_COL(CWHITE), G_COL(CWHITE), B_COL(CWHITE));
	// 
	// tmp = add_object(d->o);
	// tmp->obj = create_plane(-1, 0, 0, 2);
	// tmp->type = PLANE;
	// tmp->color = put_col(R_COL(CWHITE), G_COL(CWHITE), B_COL(CWHITE));
}

static void				init_cam(t_cam *c)
{
	c->p = vec3_new(0, 0, -10);
	c->vd = vec3_new(0, 0, 1);
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
	init_cam(&d->c);
	init_obj(d);
	init_light(d);
	printf("upleft cood %f, %f, %f\n", d->c.upleft.x, d->c.upleft.y, d->c.upleft.z);
	return (d);
}