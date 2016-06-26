/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/26 20:27:54 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			destroy_mlx(t_data *d);
t_data			*init(void);
void			color_pixel(t_data *d, unsigned int col, int x, int y);
void			render(t_data *d);



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
	unsigned int i;
	i = (unsigned int)((X_HALF + x) * d->bpp + (Y_HALF + y) * d->size);
	if (i < d->max_size)
	{
		d->dimg[i] = (char)col;
		d->dimg[i + 1] = (char)(col >> 8);
		d->dimg[i + 2] = (char)(col >> 16);
	}
}

void			render(t_data *d)
{
	int i = X_HALF;
	int j;

	while (--i > -X_HALF)
	{
		j = Y_HALF;
		while (--j > -Y_HALF)
		{
			d->dmin= INFINITY;
			color_pixel(d, CPINK, i, j);
		}
	}
}

int				expose_hook(t_data *d)
{
	double	dframe;

	d->lastime = clock();
	render(d);
	d->time = clock();
	dframe = d->time - d->lastime;
	printf("last %zu, now %zu, Delta %f\n", d->time, d->lastime, dframe);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (1);
}

int				key_hook(int key, t_data *d)
{
	if (key == ESC)
		destroy_mlx(d);
	expose_hook(d);
	return (1);
}

int				mouse_hook(int b, int x, int y, t_data *d)
{
	printf("But: %i, x: %i, y: %i\n", b, x, y);
	(void)d;
	expose_hook(d);
	return (1);
}

int				mouse_hook_move(int x, int y, t_data *d)
{
	printf("x: %i, y: %i\n", x, y);
	(void)d;
	expose_hook(d);
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
	d->bpp /= 8;
	d->max_size = (unsigned int)(d->size * Y_WIN + d->bpp * X_WIN);
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
