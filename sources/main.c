/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/03 19:32:19 by mwilk            ###   ########.fr       */
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

double			solve_2nd_deg(double a, double b, double c)
{
	float	d;
	double	ret;
	double	ret2;

	d = (b * b) - (4 * a * c);
	ret = 0;
	if (d > 0)
	{
		d = sqrt(d);
		ret = (-b - d) / (2 * a);
		ret2 = (-b + d) / (2 * a);
		if (ret2 < ret)
			ret = ret2;
	}
	return (ret);
}

double			hitsphere(t_data *d, t_sphere *s)
{
	double	a;
	double	b;
	double	c;
	double	t;

	a = vecdot(&d->r.vd, &d->r.vd);
	b = 2 * d->r.vd.x * (d->r.o.x - s->p.x);
	b += 2 * d->r.vd.y * (d->r.o.y - s->p.y);
	b += 2 * d->r.vd.z * (d->r.o.z - s->p.z);
	c = (d->r.o.x - s->p.x) * (d->r.o.x - s->p.x);
	c += (d->r.o.y - s->p.y) * (d->r.o.y - s->p.y);
	c += (d->r.o.z - s->p.z) * (d->r.o.z - s->p.z);
	c -= s->r * s->r;
	t = solve_2nd_deg(a, b ,c);
	return (t);
}

t_vec3			get_ray_dir(t_data *d, int x, int y)
{
	t_vec3	dir;

	dir.x = (2.0f * ((x + 0.5f) / X_WIN) - 1.0);
	dir.y = (1.0f - 2.0f * ((y + 0.5) / Y_WIN));
	dir.z = -1;
	dir = normalize(dir);
	return (dir);
}

t_sphere		create_sphere(int x, int y, int z, int r)
{
	t_sphere	s;
	t_vec3		p;

	p.x = x;
	p.y = y;
	p.z = z;
	s.p = p;
	s.r = r;
	return (s);
}


void			find_closest_intersection(t_data *d, t_sphere *s, int x, int y)
{
	d->r.vd = get_ray_dir(d, x, y);
	if (hitsphere(d, s))
		color_pixel(d, CPINK, x, y);
}

void			render(t_data *d)
{
	t_sphere	s;
	int			i;
	int			j;

	i = -X_HALF;
	j = Y_HALF;
	printf("I and J %i, %i\n", i, j);
	while (--j > -Y_HALF)
	{
		i = -X_HALF;
		while (++i < X_HALF)
		{
			s = create_sphere(0, 0, 100, 2);
			find_closest_intersection(d, &s, i, j);
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
	return (1);
}

static void		print_usage(void)
{
	tt_pl("Usage: ./rt [scene]");
}

int					ray_sphere(t_cam *c, t_sphere s)
{
	(void)c;
	(void)s;
	return (1);
}

void				init_cam(t_cam *c)
{
	t_vec3	v;

	v.x = -X_HALF;
	v.y = Y_HALF;
	v.z = c->f;
	c->upleft = normalize(v);
	c->w = 0.35f;
	c->h = 0.5f;
	c->f = 1.0f;
	c->p.x = 0;
	c->p.y = 0;
	c->p.z = 0;
	c->v.x = 1;
	c->v.y = 1;
	c->v.z = 1;
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
	init_cam(&d->c);
	printf("upleft cood %f, %f, %f\n", d->c.upleft.x, d->c.upleft.y, d->c.upleft.z);
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
		mlx_expose_hook(d->win, expose_hook, d);
		mlx_loop(d->mlx);
	}
	else
		print_usage();
	return (0);
}
