/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/15 15:39:42 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <time.h>

void			destroy_mlx(t_data *d)
{
	if (d->img)
		mlx_destroy_image(d->mlx, d->img);
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
	{
		free(d->mlx);
		exit(0);
	}
}

void			color_pixel(t_data *d, unsigned int col, int x, int y)
{
	int i;
	i = x * d->bpp + y * d->size;
	if (i > 0 && i < d->max_size)
	{
		d->dimg[i] = col;
		d->dimg[i + 1] = col >> 8;
		d->dimg[i + 2] = col >> 16;
	}
}

int				expose_hook(t_data *d)
{
	int i = 10;
	while (--i)
		color_pixel(d, CRED, i * 5, i * 7);
	mlx_do_sync(d->mlx);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (1);
}

int				key_hook(int key, t_data *d)
{
	if (key == ESC)
		destroy_mlx(d);
	return (1);
}

int				mouse_hook(int b, int x, int y, t_data *d)
{
	(void)b;
	(void)x;
	(void)y;
	(void)d;
	return (1);
}

int				mouse_hook_move(int x, int y, t_data *d)
{
	(void)x;
	(void)y;
	(void)d;
	return (1);
}

static void		print_usage(void)
{
	tt_pl("Usage: ./rt [scene]");
}

t_data			*init(void)
{
	t_data	*d;

	d = tt_malloc(sizeof(t_data));
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, X_WIN, Y_WIN, "RT");
	d->img = mlx_new_image(d->mlx, X_WIN, Y_WIN);
	d->dimg = mlx_get_data_addr(d->img, &d->bpp, &d->size, &d->endian);
	d->max_size = d->size * Y_WIN + d->bpp * X_WIN;
	return (d);
}

int				main(int ac, char **av)
{
	t_data	*d;

	d = NULL;
	(void)av;
	if (ac == 2)
	{
		d = (t_data *)init();
		mlx_hook(d->win, 2, 1, key_hook, d);
		mlx_hook(d->win, 4, 4, mouse_hook, d);
		mlx_hook(d->win, 6, 16, mouse_hook_move, d);
		mlx_expose_hook(d->win, expose_hook, d);
		mlx_loop(d->mlx);
	}
	else
		print_usage();
	return (0);
}
