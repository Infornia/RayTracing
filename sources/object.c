/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:01:29 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/08 11:58:49 by mwilk            ###   ########.fr       */
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

t_object		*add_object(t_object *obj, double type, t_vec3 v, double r)
{
	t_object	*o;
	
	o = create_object(obj);
	if (type == SPHERE)
	{
		o->type = SPHERE;
		o->obj = create_sphere(v, r);
		o->intersection = (t_inter)hitsphere;
	}
	else if (type == PLANE)
	{
		o->type = PLANE;
		o->obj = create_plane(v, r);
		o->intersection = (t_inter)hitplane;
	}
	else if (type == CONE)
	{
		o->type = CONE;
		o->obj = create_cone(v, r, 1);
		o->intersection = (t_inter)hitcone;
	}
	return (o);
}
