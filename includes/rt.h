/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 12:45:06 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/27 17:10:48 by mwilk            ###   ########.fr       */
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
# define ZOOM_IN	24
# define ZOOM_OUT	27
# define IT_UP	30
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
# define ZOOM_IN_M	5
# define ZOOM_OUT_M	4

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
	t_vec3				v;
	float				t;
}						t_ray;

typedef struct			s_cam
{
	t_vec3				v;
	float				p[3];
	float				w;
	float				h;
	float				f;
	float				upleft;

}						t_cam;

typedef struct			s_sphere
{
	t_vec3				p;
	double				r;
}						t_sphere;

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
	void				*mlx;
	void				*win;
	void				*img;
	char				*dimg;
	int					bpp;
	int					size;
	int					endian;
	unsigned int		max_size;

	float				dmin;

	size_t				lastime;
	size_t				time;
}						t_data;

/*
**Prototypes
*/

/*
*******************INIT
*/


/*
*******************HOOKS
*/

int				expose_hook(t_data *d);
int				mouse_hook(int button, int x, int y, t_data *d);
int				mouse_hook_move(int x, int y, t_data *d);
int				key_hook(int keycode, t_data *d);

#endif
