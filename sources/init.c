/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:16:34 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/11 19:43:40 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		init_light(t_data *d)
{
	t_light		*tmp;
	
	tmp = create_light(NULL, 3, 3, 10);
	d->l = tmp;
	tmp->type = OMNI;
	tmp->color = put_col(R_COL(CRED), G_COL(CRED), B_COL(CRED));

	tmp = create_light(tmp, -3, -3, 10);
	tmp->type = OMNI;
	tmp->color = put_col(R_COL(CBLUE), G_COL(CBLUE), B_COL(CBLUE));
	
	tmp = create_light(tmp, -5, 3, 0);
	tmp->type = OMNI;
	tmp->color = put_col(R_COL(CGREEN), G_COL(CGREEN), B_COL(CGREEN));

	tmp = create_light(tmp, 5, -3, 0);
	tmp->type = OMNI;
	tmp->color = put_col(R_COL(CGREEN), G_COL(CGREEN), B_COL(CGREEN));
}

static void		init_obj(t_data *d)
{
	t_object	*tmp;
	
	tmp = add_object(NULL);
	d->o = tmp;
	tmp->type = SPHERE;
	tmp->obj = create_sphere(-1, -1, 5, 1);
	tmp->color = put_col(R_COL(CBLUE), G_COL(CBLUE), B_COL(CBLUE));
	
	tmp = add_object(d->o);
	tmp->obj = create_sphere(1, 1, 5, 1);
	tmp->type = SPHERE;
	tmp->color = put_col(R_COL(CRED), G_COL(CRED), B_COL(CRED));
	
	tmp = add_object(d->o);
	tmp->obj = create_plane(0, -1, 0, 2);
	tmp->type = PLANE;
	tmp->color = put_col(R_COL(CWHITE), G_COL(CWHITE), B_COL(CWHITE));

	tmp = add_object(d->o);
	tmp->obj = create_plane(0, 1, 0, 2);
	tmp->type = PLANE;
	tmp->color = put_col(R_COL(CWHITE), G_COL(CWHITE), B_COL(CWHITE));
}

static void				init_cam(t_cam *c)
{
	c->p = vec3_new(0, 0, -10);
	c->vd = vec3_new(0, 0, 1);
	c->w = 0.5;
	c->h = 0.35;
	c->f = 1.0;
	c->fov = tan((20 * M_PI) / 180);
}

t_data			*init(void)
{
	t_data	*d;

	d = tt_malloc(sizeof(t_data));
	init_mlx(d);
	init_cam(&d->c);
	init_obj(d);
	init_light(d);
	printf("upleft cood %f, %f, %f\n", d->c.upleft.x, d->c.upleft.y, d->c.upleft.z);
	return (d);
}