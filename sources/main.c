/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/27 19:41:15 by mwilk            ###   ########.fr       */
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

t_vec3		vecsub(t_vec3 *a, t_vec3 *b)
{
	t_vec3	v;

	v.x = a->x - b->x;
	v.y = a->y - b->y;
	v.z = a->z - b->z;
	return (v);
}

double			vecdot(t_vec3 *a, t_vec3 *b)
{
	return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));
}

int				hitsphere(t_ray *r, t_sphere *s)
{
	t_vec3	dist;
	double	b;
	double	d;
	double	t0;
	double	t1;
	int		ret;

	dist.x = s.p.x - r.o.x;
	dist.y = s.p.y - r.o.y;
	dist.z = s->p.z - r->o.z;
	b = r->v.z * dist.z;
	d = b * b - dist.z * dist.z + s->r * s->r;
	ret = 0;
	if (d < 0.0f)
		return (0);
	t0 = b - sqrtf(d);
	t1 = b + sqrtf(d);
	if ((t0 > 0.1f) && (t0 < r->t) && (ret = 1))
		r->t = t0;
	if ((t1 > 0.1f) && (t1 < r->t) && (ret = 1))
		r->t = t1;
	printf("t0: %f, t1: %f, t: %f,\n", t0, t1, r->t);
	return (ret);
}

void				next(t_data *d, int x, int y)
{
	float		color = 0;
	float		coef = 1;
	int			level = 1;
	t_ray		r;
	t_sphere	s;

	r.o.x = x;
	r.o.y = y;
	r.o.z = -10000.0f;
	r.v.x = 0.0f;
	r.v.y = 0.0f;
	r.v.z = 1.0f;
	s.p.x = 0.0f;
	s.p.y = 0.0f;
	s.p.z = 100.0f;
	s.r = 1.0f;
	while ((coef > 0.0f) && (level < 10))
	{
		//INTERS
		int		sphere_cur = -1;
		int		i = 0;
		float	newstart;

		r.t = 20000.0f;
		if (hitsphere(&r, &s))
		{
			color = CQUOISE;
			sphere_cur = 1;
		}
		else
			break ;
		newstart = r.o.z + r.t * r.v.z;
		r.o.z = newstart;
	}
	color_pixel(d, color, x, y);
}

void			render(t_data *d)
{
	int			i = X_HALF;
	int			j;

	while (--i > -X_HALF)
	{
		j = Y_HALF;
		while (--j > -Y_HALF)
		{
			next(d, i, j);
			d->dmin= INFINITY;
//			color_pixel(d, CPINK, i, j);
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

int					mouse_hook(int b, int x, int y, t_data *d)
{
	printf("But: %i, x: %i, y: %i\n", b, x, y);
	(void)d;
	return (1);
}

int					mouse_hook_move(int x, int y, t_data *d)
{
	printf("x: %i, y: %i\n", x, y);
	(void)d;
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

void				init_cam(t_data *d)
{
	d->c.w = 0.35f;
	d->c.h = 0.5f;
	d->c.f = 1.0f;
	d->c.p[0] = 0;
	d->c.p[1] = 0;
	d->c.p[2] = 0;
	d->c.v.x = 1;
	d->c.v.y = 1;
	d->c.v.z = 1;

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
