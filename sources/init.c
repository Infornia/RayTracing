/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:16:34 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/09 19:02:26 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		init_light(t_data *d)
{
	t_light		*tmp;
	
	tmp = create_light(NULL, 10, 10, 3);
	d->l = tmp;
	tmp->type = OMNI;
	tmp->color = put_col(R_COL(CRED), G_COL(CRED), B_COL(CRED));

	tmp = create_light(tmp, -10, 10, 3);
	tmp->type = OMNI;
	tmp->color = put_col(R_COL(CBLUE), G_COL(CBLUE), B_COL(CBLUE));
}

static void		init_obj(t_data *d)
{
	t_object	*tmp;
	
	tmp = add_object(NULL);
	d->o = tmp;
	tmp->type = SPHERE;
	tmp->obj = create_sphere(0, 0, 10, 3);
	tmp->color = put_col(R_COL(CWHITE), G_COL(CWHITE), B_COL(CWHITE));
	
	// tmp = add_object(d->o);
	// tmp->obj = create_plane(0, 1, 0, 2);
	// tmp->type = PLANE;
	// put_col(&tmp->color, CWHITE);
}

static void				init_cam(t_cam *c)
{
	c->p.x = 0;
	c->p.y = 0;
	c->p.z = 0;
}

t_data			*init(void)
{
	t_data	*d;

	d = tt_malloc(sizeof(t_data));
	init_mlx(d);
	init_cam(&d->c);
	init_obj(d);
	init_light(d);
	d->fov = tan((20 * M_PI) / 180);
	printf("upleft cood %f, %f, %f\n", d->c.upleft.x, d->c.upleft.y, d->c.upleft.z);
	return (d);
}