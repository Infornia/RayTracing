/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 19:08:09 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/27 15:41:20 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_light			*create_light(t_light *l)
{
	t_light	*tmp;
	
	tmp = l;
	if (!tmp)
	{
		tmp = tt_malloc(sizeof(t_light));
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = tt_malloc(sizeof(t_light));
		tmp->next->next = NULL;
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
	return (tmp);
}

t_light			*add_light(t_light *l, double x, double y, double z)
{
	t_ray		r;

	l = create_light(l);
	r.o.x = x;
	r.o.y = y;
	r.o.z = z;
	l->r = r;
	l->angle = 0;
	return (l);
}