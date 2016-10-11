/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:21:32 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/11 17:18:19 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			color_pixel(t_data *d, unsigned int col, int x, int y)
{
	unsigned int i;
	i = x * d->bpp + y * d->size;
	if (i < d->max_size)
	{
		d->dimg[i] = (char)col;
		d->dimg[i + 1] = (char)(col >> 8);
		d->dimg[i + 2] = (char)(col >> 16);
	}
}

t_color		moy_col(t_color c)
{
	float	x;
	
	x = c.r;
	x = c.g > x ? c.g : x;
	x = c.b > x ? c.b : x;
	if (x > 255)
	{
		c.r *= 255 / x;
		c.g *= 255 / x;
		c.b *= 255 / x;
	}
	return (c);
}

t_color		add_col(t_color c, float r, float g, float b)
{
	c.r += r;
	c.g += g;
	c.b += b;
	return (c);
}

t_color		put_col(float r, float g, float b)
{
	t_color	c;
	
	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}