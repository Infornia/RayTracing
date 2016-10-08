/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:51:38 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/08 19:45:02 by mwilk            ###   ########.fr       */
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

typedef struct			s_light
{
	t_ray				r;
	int					type;
	float				range;
	t_color				color;
	struct s_light		*next;
	struct s_light		*prev;
}						t_light;

typedef struct			s_sphere
{
	t_vec3				p;
	float				r;
}						t_sphere;

typedef struct			s_hitpoint
{
	t_vec3				p;
	t_vec3				n;
}						t_hitpoint;

typedef struct			s_plane
{
	t_vec3				vd;
	double				offset;
}						t_plane;

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
	double				fov;
	unsigned int		max_size;

	float				tmin;
	size_t				lastime;
	size_t				time;
}						t_data;
