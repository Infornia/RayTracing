/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:42:02 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/03 19:29:05 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3			normalize(t_vec3 v)
{
	float l;

	l = sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	v.x /= (float)l;
	v.y /= (float)l;
	v.z /= (float)l;
	return (v);
}

t_vec3		vecsub(t_vec3 *a, t_vec3 *b)
{
	t_vec3	v;

	v.x = a->x - b->x;
	v.y = a->y - b->y;
	v.z = a->z - b->z;
	return (v);
}

t_vec3		vecadd(t_vec3 *a, t_vec3 *b)
{
	t_vec3	v;

	v.x = a->x + b->x;
	v.y = a->y + b->y;
	v.z = a->z + b->z;
	return (v);
}

double			vecdot(t_vec3 *a, t_vec3 *b)
{
	return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));
}
