/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:16:34 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/07 15:27:21 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_object		*add_object(t_object *o)
{
	t_object	*tmp;
	
	printf("Entering\n");
	tmp = o;
	if (!tmp)
	{
		printf("NEW OBJ\n");
		tmp = tt_malloc(sizeof(t_object));
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	else
	{
		printf("NEW OBJ2\n");
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = tt_malloc(sizeof(t_object));
		tmp->next->next = NULL;
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
	return (tmp);
}

static void		init_obj(t_data *d)
{
	t_object	*tmp;
	
	d->nb_obj = 2;
	d->o = NULL;
	tmp = add_object(d->o);
	d->o = tmp;
	tmp->type = SPHERE;
	tmp->obj = create_sphere(0, 0, 0, 3);
	put_col(&tmp->color, CPINK);
	
	tmp = add_object(d->o);
	tmp->obj = create_plane(0, 1, 0, 2);
	tmp->type = PLANE;
	put_col(&tmp->color, CWHITE);
}

static void				init_mlx(t_data *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, X_WIN, Y_WIN, "RT");
	d->img = mlx_new_image(d->mlx, X_WIN, Y_WIN);
	d->dimg = mlx_get_data_addr(d->img, &d->bpp, &d->size, &d->endian);
	d->bpp /= 8;
	d->max_size = (unsigned int)(d->size * Y_WIN + d->bpp * X_WIN);
}

static void				init_cam(t_cam *c)
{
	c->p.x = 0;
	c->p.y = 0;
	c->p.z = 10;
}

t_data			*init(void)
{
	t_data	*d;

	d = tt_malloc(sizeof(t_data));
	init_mlx(d);
	init_cam(&d->c);
	init_obj(d);
	d->fov = tan((20 * M_PI) / 180);
	printf("upleft cood %f, %f, %f\n", d->c.upleft.x, d->c.upleft.y, d->c.upleft.z);
	return (d);
}