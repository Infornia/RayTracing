/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:51:38 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/01 16:40:06 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct			s_data		t_data; 
typedef struct			s_ray		t_ray;
typedef struct			s_hitpoint	t_hitpoint;
typedef struct			s_object	t_object;

typedef t_hitpoint		(*t_inter)(t_ray *r, t_object *o);

typedef struct			s_color
{
	unsigned int		r;
	unsigned int		g;
	unsigned int		b;
}						t_color;

typedef struct			s_vec3
{
	double				x;
	double				y;
	double				z;
}						t_vec3;

typedef struct			s_param
{
	double				a;
	double				b;
	double				c;
	double				det;
}						t_param;

struct					s_ray
{
	t_vec3				o;
	t_vec3				dir;
};

typedef struct			s_cam
{
	t_vec3				p;
	t_vec3				vd;
	t_vec3				upleft;
	double				w;
	double				h;
	double				f;
	double				fov;

}						t_cam;

typedef struct			s_light
{
	t_ray				r;
	t_vec3				spotlight;
	int					type;
	int					radius;
	double				angle;
	t_color				color;
	struct s_light		*next;
	struct s_light		*prev;
}						t_light;

typedef struct			s_sphere
{
	t_vec3				p;
	double				r;
	double				r_square;
	t_color				color;
}						t_sphere;

typedef struct			s_cone
{
	t_vec3				p;
	double				r;
	double				h;
	t_color				color;
}						t_cone;


typedef struct			s_plane
{
	t_vec3				n;
	double				d;
	t_color				color;
}						t_plane;

typedef struct			s_material
{
	t_vec3				color;
	double				diffuse;
	double				specular;
}						t_material;


struct					s_object
{
	void				*obj;
	t_inter				intersection;
	void				*normalize;
	int					type;
	
	t_color				color;
	int					material;
	t_color				specular;
	t_color				diffuse;
	t_color				ambient;
	t_color				self_illu;
	
	double				shininess;
	double				shinestrength;
	double				transmittivity;
	double				reflectivity;
	
	int					permanent;
	struct s_object		*next;
	struct s_object		*prev;
};

struct					s_hitpoint
{
	double				t;
	t_vec3				p;
	t_vec3				n;
	t_color				c;
	t_material			m;
};


struct					s_data
{
	t_cam				cam;
	t_ray				r;
	t_hitpoint			h;
	t_color				c;
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
};
























