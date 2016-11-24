/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 12:00:52 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/10 17:20:52 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rt.h"

t_hitpoint		miss(void)
{
	t_hitpoint	h;
	
	h.t = MAX_DIST;
	return (h);
}

int				find_intersection(t_object *o, t_ray *r)
{
	t_object	*tmp;
	t_hitpoint	h;
	
	tmp = o;
	while (tmp)
	{
		h = tmp->intersection(r, tmp->obj);
		if (h.t < MAX_DIST)
			return (1);
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
		if (h.t < ret.t)
			ret = h;
		tmp = tmp->next;
	}
	return (ret);
}