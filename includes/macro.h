/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:53:05 by mwilk             #+#    #+#             */
/*   Updated: 2016/10/07 16:36:00 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Parameters
*/

# define X_WIN 			800
# define Y_WIN 			600
# define Y_HALF 		Y_WIN / 2
# define X_HALF 		X_WIN / 2
# define FOV 			tan(20 * M_PI) / 180

/*
** Objects
*/

# define NB_OBJECT_TYPE	2
# define SPHERE			0
# define PLANE			1
# define EPSILON		0.001

/*
**Colors
*/
# define CRED			0xFF0000
# define CGREEN			0x00FF00
# define CBLUE 			0x0000FF
# define CQUOISE		0x74BDF9
# define CGREEN 		0x00FF00
# define CPINK 			0xFF00FF
# define CWHITE 		0xFFFFFF
# define CGRAY 			0x0F0F0F
# define CBLACK 		0x000000
# define RGB(r, g, b)	(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define R_COL(c)		(c) & 0xFF	
# define G_COL(c)		(c >> 8) & 0xFF	
# define B_COL(c)		(c >> 16) & 0xFF	


/*
**maths
*/

# define ABS(x)			((x) < 0 ? -(x) : (x))

/*
**keys
*/

# define ESC			53
# define UP				126
# define DOWN			125
# define LEFT			123
# define RIGHT			124
# define TAB			48
# define SHIFT			257
# define PLUS			24
# define MINUS			27
# define IT_UP			30
# define IT_DOWN		33
# define OPT_UP			39
# define OPT_DOWN		41
# define KEY1			18
# define KEY2			19
# define NUM0			29
# define NUM1			83
# define NUM2			84
# define NUM3			85
# define NUM4			86
# define NUM5			87
# define NUM6			88
# define KEYR			15
# define SPACE			49
# define CTRL			269
# define ZOOM_IN_M		5
# define ZOOM_OUT_M		4