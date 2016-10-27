/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 20:04:09 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/27 17:55:04 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		tt_print(t_ray *r, t_object *obj, t_light *light)
{
	static int	n = 3;
	t_object	*o;
	t_light		*l;
	
	o = obj ? obj : NULL;
	l = light ? light : NULL;
	if (n)
	{
		printf("\n\nTHE N IS HERRRRRRRRRE ---> %i\n", n);
		n--;
		if (r)
		{
			printf("\nRAY\n");
			printf("Origin: %f, %f, %f\n", r->o.x, r->o.y, r->o.z);
			printf("Direction: %f, %f, %f\n", r->dir.x, r->dir.y, r->dir.z);
		}
		while (o)
		{
			
			if (o->type == SPHERE)
			{
				printf("\nOBJECT SPHERE\n");
				printf("Pos: %f, %f, %f\n", ((t_sphere *)(o->obj))->p.x, ((t_sphere *)(o->obj))->p.y, ((t_sphere *)(o->obj))->p.z);
				printf("Rad: %f\n", ((t_sphere *)(o->obj))->r);
			}
			if (o->type == PLANE)
			{
				printf("\nOBJECT PLANE\n");
				printf("Pos: %f, %f, %f\n", ((t_plane *)(o->obj))->n.x, ((t_plane *)(o->obj))->n.y, ((t_plane *)(o->obj))->n.z);
				printf("Rad: %f\n", ((t_plane *)(o->obj))->d);
			}
			o = o->next;
		}
		while (l)
		{
			printf("\nOBJECT LIGHT\n");
			printf("Type: %d\n", l->type);
			printf("Origin: %f, %f, %f\n", l->r.o.x, l->r.o.y, l->r.o.z);
			printf("Direction: %f, %f, %f\n", l->r.dir.x, l->r.dir.y, l->r.dir.z);
			l = l->next;
		}
	}
}