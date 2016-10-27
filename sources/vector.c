/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:42:02 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/27 17:11:04 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3		vec3_new(double x, double y, double z)
{
	t_vec3	v;
	
	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec3		normalize(t_vec3 v)
{
	double l;

	l = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
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

t_vec3		vec_neg(t_vec3 a)
{
	a.x = -a.x;
	a.y = -a.y;
	a.z = -a.z;
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

t_vec3			vec_scalar(t_vec3 v, double scal)
{
	v.x *= scal;
	v.y *= scal;
	v.z *= scal;
	return (v);
}