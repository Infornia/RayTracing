/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:42:02 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/08 18:37:03 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3		*vec3_new(float x, float y, float z)
{
	t_vec3	*v;
	
	v = tt_malloc(sizeof(t_vec3));
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

t_vec3			normalize(t_vec3 v)
{
	float l;

	l = sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	v.x /= l;
	v.y /= l;
	v.z /= l;
	return (v);
}

t_vec3		vec_sub(t_vec3 *a, t_vec3 *b)
{
	t_vec3	v;

	v.x = a->x - b->x;
	v.y = a->y - b->y;
	v.z = a->z - b->z;
	return (v);
}

t_vec3		vec_add(t_vec3 *a, t_vec3 *b)
{
	t_vec3	v;

	v.x = a->x + b->x;
	v.y = a->y + b->y;
	v.z = a->z + b->z;
	return (v);
}

double			vec_dot(t_vec3 *a, t_vec3 *b)
{
	return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));
}

t_vec3			vec_scalar(t_vec3 *v, float coef_mult)
{
	t_vec3	ret;

	ret.x = v->x * coef_mult;
	ret.y = v->y * coef_mult;
	ret.z = v->z * coef_mult;
	return (ret);
}