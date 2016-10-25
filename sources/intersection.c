/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 12:00:52 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/25 17:45:10 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rt.h"

t_hitpoint		miss(void)
{
	t_hitpoint	h;
	
	h.t = 0.0;
	return (h);
}

int				find_intersection(t_object *o, t_light *l)
{
	t_object	*tmp;
	t_hitpoint	h;
	float		limit;
	
	tmp = o;
	limit = l->radius ? l->radius : MAX_DIST;
	while (tmp)
	{
		h.t = limit;
		h = tmp->intersection(&l->r, tmp->obj);
		plane(&l->r, tmp->obj);
			// printf("the t: %f the norm : %f, %f, %f \n", h.t, h.n.x, h.n.y, h.n.z);
		if (h.t > EPSILON && h.t < limit)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

t_hitpoint	find_closest_intersection(t_object *o, t_ray *r)
{
	t_object	*tmp;
	t_hitpoint	h;
	t_hitpoint	ret;
	
	ret.t = MAX_DIST;
	tmp = o;
	while (tmp)
	{
		h = tmp->intersection(r, tmp->obj);
		 tmp->obj);
		if (h.t >= EPSILON && h.t < ret.t)
			ret = h;
		tmp = tmp->next;
	}
	return (ret);
}