/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 12:45:06 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/15 13:12:50 by mwilk            ###   ########.fr       */
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
# include "../libft/includes/libft.h"

/*
**Parameters
*/

# define X_WIN 800
# define Y_WIN 600
# define Y_HALF Y_WIN / 2
# define X_HALF X_WIN / 2
# define NB_FRACTAL 8
# define NB_PAL 7
# define NB_TREE_COLORS 7
# define NB_TRI_COLORS 4
# define NB_TRI_OPT 3

/*
** Textures
*/
# define T_PAL			"textures/pal.xpm"
# define T_PAL1			"textures/pal1.xpm"
# define T_PAL2			"textures/pal2.xpm"
# define T_PAL3			"textures/pal3.xpm"
# define T_PAL4			"textures/pal4.xpm"
# define T_PAL5			"textures/pal5.xpm"
# define T_PAL6			"textures/pal6.xpm"

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

typedef struct			s_data
{
	void			*mlx;
	void			*win;
	void		*img;
	char		*data_img;
	int			bpp;
	int			size;
	int			endian;
	int			max_size;
	int			w;
	int			h;
}					t_data;

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