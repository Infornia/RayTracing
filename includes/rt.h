/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 12:45:06 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/26 15:44:14 by mwilk            ###   ########.fr       */
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
t_color			scal_col(t_color c, float scal);
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
int				find_intersection(t_object *o, t_light *l);

/*
*******************LIGHT.C
*/
t_light			*add_light(t_light *l, float x, float y, float z);
t_light			*create_light(t_light *l);

/*
*******************MLX.C
*/

void			init_mlx(t_data *d);
void			destroy_mlx(t_data *d);

/*
*******************OBJECT.C
*/

t_object		*add_object(t_object *o, int type, int x, int y, int z, int r);
t_object		*create_object(t_object *o);

/*
*******************PLANE.C
*/

t_hitpoint		hitplane(t_ray *r, t_plane *p);
t_plane			*create_plane(float vx, float vy, float vz, float d);

/*
*******************SPHERE.C
*/

t_sphere		*create_sphere(int x, int y, int z, int r);
t_hitpoint		hitsphere(t_ray *r, t_sphere *s);


/*
*******************VECTOR.C
*/
t_vec3			normalize(t_vec3 v);
t_vec3			vec3_new(float x, float y, float z);
t_vec3			vec_sub(t_vec3 a, t_vec3 b);
t_vec3			vec_add(t_vec3 a, t_vec3 b);
t_vec3			vec_neg(t_vec3 a);
t_vec3			vec_mul(t_vec3 a, t_vec3 b);
double			vec_dot(t_vec3 a, t_vec3 b);
t_vec3			vec_scalar(t_vec3 v, float coef_mult);

/*
*******************UTILS.C
*/
void			tt_print(t_ray *r, t_object *o, t_light *l);

#endif