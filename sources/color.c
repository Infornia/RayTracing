/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:21:32 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/25 18:28:41 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		color_pixel(t_data *d, unsigned int col, int x, int y)
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

t_color		lim_col(t_color c)
{
	c.r = c.r > 255 ? 255 : c.r;
	c.g = c.g > 255 ? 255 : c.g;
	c.b = c.b > 255 ? 255 : c.b;
	return (c);
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

t_color		add_col(t_color c, t_color c2)
{
	c.r += c2.r;
	c.g += c2.g;
	c.b += c2.b;
	return (c);
}

t_color		mult_col(t_color c, t_color c2)
{
	c.r *= c2.r;
	c.g *= c2.g;
	c.b *= c2.b;
	return (c);
}

t_color		scal_col(t_color c, float scal)
{
	c.r *= scal;
	c.g *= scal;
	c.b *= scal;
	return (c);
}

t_color		put_col(unsigned int color)
{
	t_color	c;
	
	c.r = R_COL(color);
	c.g = G_COL(color);
	c.b = B_COL(color);
	return (c);
}