/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:42:02 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/24 19:40:46 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3		vec3_new(float x, float y, float z)
{
	t_vec3	v;
	
	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec3		normalize(t_vec3 v)
{
	float l;

	l = sqrtf(vec_dot(v, v));
	v.x /= l;
	v.y /= l;
	v.z /= l;
	return (v);
}

t_vec3		vec_sub(t_vec3 a, t_vec3 b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_vec3		vec_add(t_vec3 a, t_vec3 b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_vec3		vec_mul(t_vec3 a, t_vec3 b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return (a);
}

double			vec_dot(t_vec3 a, t_vec3 b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vec3			vec_scalar(t_vec3 v, float scal)
{
	v.x *= scal;
	v.y *= scal;
	v.z *= scal;
	return (v);
}