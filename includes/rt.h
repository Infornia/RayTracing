/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 12:45:06 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/05 18:48:23 by mwilk            ###   ########.fr       */
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

/*
**Parameters
*/

# define X_WIN 800
# define Y_WIN 600
# define Y_HALF Y_WIN / 2
# define X_HALF X_WIN / 2
# define FOV tan(20 * M_PI) / 180


/*
**Colors
*/
# define CRED		0xFF0000
# define CGREEN		0x00FF00
# define CBLUE 		0x0000FF
# define CQUOISE	0x74BDF9
# define CGREEN 	0x00FF00
# define CPINK 		0xFF00FF
# define CWHITE 	0xFFFFFF
# define CGRAY 		0x0F0F0F
# define CBLACK 	0x000000
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define ABS(x)		((x) < 0 ? -(x) : (x))

/*
**keys
*/

# define ESC		53
# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define TAB		48
# define SHIFT		257
# define PLUS		24
# define MINUS		27
# define IT_UP		30
# define IT_DOWN	33
# define OPT_UP		39
# define OPT_DOWN	41
# define KEY1		18
# define KEY2		19
# define NUM0		29
# define NUM1		83
# define NUM2		84
# define NUM3		85
# define NUM4		86
# define NUM5		87
# define NUM6		88
# define KEYR		15
# define SPACE		49
# define CTRL		269
# define ZOOM_IN_M	5
# define ZOOM_OUT_M	4

/*
** Objects
*/

#define SPHERE	0
#define PLANE	1

/*
**Structures
*/

typedef struct			s_vec3
{
	float				x;
	float				y;
	float				z;
}						t_vec3;

typedef struct			s_ray
{
	t_vec3				o;
	t_vec3				vd;
	float				t;
}						t_ray;

typedef struct			s_cam
{
	t_vec3				v;
	t_vec3				p;
	float				w;
	float				h;
	float				f;
	t_vec3				upleft;

}						t_cam;

typedef struct			s_sphere
{
	t_vec3				p;
	float				r;
}						t_sphere;

typedef struct			s_plane
{
	t_vec3				vd;
	double				offset;
}						t_plane;

typedef struct			s_object
{
	void				*obj;
	int					type;
	int					color;
	float				tmin;
	struct s_object		*next;
}						t_object;

typedef struct			s_intersection
{
	float				d;
	float				n;
	float				p[3];
}						t_intersection;

typedef struct			s_data
{
	t_cam				c;
	t_ray				r;
	t_object			*o;
	void				*mlx;
	void				*win;
	void				*img;
	char				*dimg;
	int					bpp;
	int					size;
	int					endian;
	double				fov;
	unsigned int		max_size;

	int					nb_obj;
	size_t				lastime;
	size_t				time;
}						t_data;

/*
**Prototypes
*/

/*
*******************INIT
*/

t_data			*init(void);

/*
*******************DRAW
*/

void			draw(t_data *d);
void			render(t_data *d);
void			color_pixel(t_data *d, unsigned int col, int x, int y);


/*
*******************HOOKS
*/

int				expose_hook(t_data *d);
int				mouse_hook(int button, int x, int y, t_data *d);
int				mouse_hook_move(int x, int y, t_data *d);
int				key_hook(int keycode, t_data *d);

/*
*******************VECTORS
*/
t_vec3			normalize(t_vec3 v);
t_vec3			vecsub(t_vec3 *a, t_vec3 *b);
t_vec3			vecadd(t_vec3 *a, t_vec3 *b);
double			vecdot(t_vec3 *a, t_vec3 *b);

/*
*******************MLX
*/

void			destroy_mlx(t_data *d);

/*
*******************HOOKS
*/

int				expose_hook(t_data *d);
int				key_hook(int key, t_data *d);

/*
*******************CALCULATE
*/

double			solve_2nd_deg(double a, double b, double c);
t_vec3			get_ray_dir(t_data *d, int x, int y);
void			find_closest_intersection(t_data *d, t_object *o, int x, int y);


/*
*******************OBJECTS
*/

double			hitsphere(t_data *d, t_sphere *s);
double			hitplane(t_data *d, t_plane *p);
void			new_object(t_object *o, int type);
t_sphere		*create_sphere(int x, int y, int z, int r);
t_plane			*create_plane(float vx, float vy, float vz, float d);

#endif






















