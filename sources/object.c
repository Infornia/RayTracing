/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:01:29 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/26 14:35:54 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_object		*create_object(t_object *o)
{
	t_object	*tmp;
	
	tmp = o;
	if (!tmp)
	{
		tmp = tt_malloc(sizeof(t_object));
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = tt_malloc(sizeof(t_object));
		tmp->next->next = NULL;
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
	return (tmp);
}

t_object		*add_object(t_object *obj, int type, int x, int y, int z, int r)
{
	t_object	*o;
	
	o = create_object(obj);
	if (type == SPHERE)
	{
		o->type = SPHERE;
		o->obj = create_sphere(x, y, z, r);
		o->intersection = (t_inter)hitsphere;
	}
	else if (type == PLANE)
	{
		o->type = PLANE;
		o->obj = create_plane(x, y, z, r);
		o->intersection = (t_inter)hitplane;
	}
	return (o);
}
