/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 12:00:52 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/17 19:03:38 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rt.h"

int				find_intersection(t_object *o, t_light *l)
{
	t_object	*tmp;
	float		t;
	float		limit;
	
	tmp = o;
	limit = l->radius ? l->radius : MAX_DIST;
	t = limit;
	while (tmp)
	{
		if (tmp->type == SPHERE)
			t = hitsphere(&l->r, tmp->obj);
		else if (tmp->type == PLANE)
			t = hitplane(&l->r, tmp->obj);
		if (t >= EPSILON && t < limit)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_hitpoint	find_closest_intersection(t_object *o, t_ray *r)
{
	t_object	*tmp;
	t_hitpoint	h;
	float		t;
	
	h.o = NULL;
	h.tmin = MAX_DIST;
	tmp = o;
	t = 0.0;
	while (tmp)
	{
		if (tmp->type == SPHERE)
			t = hitsphere(r, tmp->obj);
		else if (tmp->type == PLANE)
			t = hitplane(r, tmp->obj);
		if (t >= EPSILON && t < h.tmin)
		{
			h.tmin = t;
			h.o = tmp;
		}
		tmp = tmp->next;
	}
	return (h);
}