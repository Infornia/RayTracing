/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 12:45:06 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/13 12:44:00 by mwilk            ###   ########.fr       */
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
*******************COLOR.C
*/

void			color_pixel(t_data *d, unsigned int col, int x, int y);
t_color			put_col(float r, float g, float b);
t_color			add_col(t_color c, t_color c2);
t_color			moy_col(t_color c);
t_color			scal_col(t_color c, float scal);
t_color			mult_col(t_color c, t_color c2);

/*
*******************DRAW.C
*/

void			draw(t_data *d);
void			render(t_data *d);

/*
*******************VECTOR.C
*/
t_vec3			normalize(t_vec3 v);
t_vec3			vec3_new(float x, float y, float z);
t_vec3			vec_sub(t_vec3 a, t_vec3 b);
t_vec3			vec_add(t_vec3 a, t_vec3 b);
double			vec_dot(t_vec3 a, t_vec3 b);
t_vec3			vec_scalar(t_vec3 v, float coef_mult);

/*
*******************MLX.C
*/

void			init_mlx(t_data *d);
void			destroy_mlx(t_data *d);

/*
*******************HOOKS.C
*/

int				expose_hook(t_data *d);
int				key_hook(int key, t_data *d);

/*
*******************CALCULATE.C
*/

double			solve_2nd_deg(double a, double b, double c);
t_vec3			get_ray_dir(int x, int y);
t_object		*find_closest_intersection(t_object *o, t_ray *r, float *tmin);
t_color			compute_color(t_data *d, t_hitpoint *h, t_color c);


/*
*******************OBJECT.C
*/

t_object		*add_object(t_object *o);

/*
*******************SPHERE.C
*/

t_sphere		*create_sphere(int x, int y, int z, int r);
double			hitsphere(t_ray *r, t_sphere *s);


/*
*******************PLANE.C
*/

double			hitplane(t_ray *r, t_plane *p);
t_plane			*create_plane(float vx, float vy, float vz, float d);

/*
*******************LIGHT.C
*/
t_light			*create_light(t_light *l, float x, float y, float z);
t_light			*add_light(t_light *l);

#endif






















