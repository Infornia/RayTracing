/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 12:45:06 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/01 17:36:48 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include "../libft/includes/libft.h"
# include "macro.h"
# include "struct.h"

/*
**Prototypes
*/

/*
*******************INIT.C
*/

t_data			*init(void);

/*
*******************CALC.C
*/

t_color			compute_color(t_data *d, t_hitpoint *h, t_color c);

/*
*******************COLOR.C
*/

void			color_pixel(t_data *d, unsigned int col, int x, int y);
t_color			put_col(unsigned int c);
t_color			add_col(t_color c, t_color c2);
t_color			moy_col(t_color c);
t_color			scal_col(t_color c, double scal);
t_color			lim_col(t_color c);
t_color			mult_col(t_color c, t_color c2);

/*
*******************DRAW.C
*/

t_vec3			get_ray_dir(int x, int y);
void			render(t_data *d);
void			draw(t_data *d);

/*
*******************HOOKS.C
*/

int				expose_hook(t_data *d);
int				key_hook(int key, t_data *d);


/*
*******************INTERSECTION.C
*/

t_hitpoint		miss(void);
t_hitpoint		find_closest_intersection(t_object *o, t_ray *r);
int				find_intersection(t_object *o, t_ray r);

/*
*******************LIGHT.C
*/
t_light			*add_light(t_light *l, t_vec3 o, t_vec3 dir, unsigned int color);
t_light			*create_light(t_light *l);

/*
*******************MLX.C
*/

void			init_mlx(t_data *d);
void			destroy_mlx(t_data *d);

/*
*******************OBJECT.C
*/

t_object		*add_object(t_object *obj, double type, t_vec3 v, double r);
t_object		*create_object(t_object *o);

/*
*******************PLANE.C
*/

t_plane			*create_plane(t_vec3 n, double d);
t_hitpoint		hitplane(t_ray *r, t_plane *p);

/*
*******************SPHERE.C
*/

t_sphere		*create_sphere(t_vec3 p, double r);
t_hitpoint		hitsphere(t_ray *r, t_sphere *s);

/*
*******************SPHERE.C
*/

t_cone			*create_cone(t_vec3 p, double r, double h);
t_hitpoint		hitcone(t_ray *r, t_cone *c);

/*
*******************VECTOR.C
*/
t_vec3			normalize(t_vec3 v);
t_vec3			vec3_new(double x, double y, double z);
t_vec3			vec_sub(t_vec3 a, t_vec3 b);
t_vec3			vec_add(t_vec3 a, t_vec3 b);
t_vec3			vec_neg(t_vec3 a);
t_vec3			vec_mul(t_vec3 a, t_vec3 b);
double			vec_dot(t_vec3 a, t_vec3 b);
t_vec3			vec_scalar(t_vec3 v, double coef_mult);

/*
*******************UTILS.C
*/
void			tt_print(t_ray *r, t_object *o, t_light *l);

#endif