/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:51:38 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/20 20:37:09 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


typedef struct			s_color
{
	float	r;
	float	g;
	float	b;
}						t_color;

typedef struct			s_vec3
{
	float				x;
	float				y;
	float				z;
}						t_vec3;

typedef struct			s_ray
{
	t_vec3				o;
	t_vec3				dir;
}						t_ray;

typedef struct			s_cam
{
	t_vec3				p;
	t_vec3				vd;
	t_vec3				upleft;
	float				w;
	float				h;
	float				f;
	float				fov;

}						t_cam;

typedef struct			s_light
{
	t_ray				r;
	t_vec3				spotlight;
	int					type;
	int					radius;
	t_color				color;
	struct s_light		*next;
	struct s_light		*prev;
}						t_light;

typedef struct			s_sphere
{
	t_vec3				p;
	float				r;
	t_color				color;
}						t_sphere;


typedef struct			s_plane
{
	t_vec3				n;
	double				d;
	t_color				color;
}						t_plane;

typedef struct			s_material
{
	t_vec3		color;
	float		diffuse;
	float		specular;
}						t_material;


typedef struct			s_object
{
	void				*obj;
	int					type;
	
	t_color				color;
	int					material;
	t_color				specular;
	t_color				diffuse;
	t_color				ambient;
	t_color				self_illu;
	
	float				shininess;
	float				shinestrength;
	float				transmittivity;
	float				reflectivity;
	
	int					permanent;
	struct s_object		*next;
	struct s_object		*prev;
}						t_object;

typedef struct			s_hitpoint
{
	float				t;
	t_vec3				p;
	t_vec3				n;
	t_color				c;
	t_material			m;
}						t_hitpoint;

typedef struct			s_data
{
	t_cam				c;
	t_ray				r;
	t_hitpoint			h;
	t_object			*o;
	t_light				*l;
	void				*mlx;
	void				*win;
	void				*img;
	char				*dimg;
	int					bpp;
	int					size;
	int					endian;
	double				coef;
	unsigned int		max_size;

	size_t				lastime;
	size_t				time;
}						t_data;
