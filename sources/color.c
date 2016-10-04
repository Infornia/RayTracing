/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:21:32 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/04 17:26:07 by mwilk            ###   ########.fr       */
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