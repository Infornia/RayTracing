/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/15 13:16:19 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		main(int ac, char **av)
{
	t_data	*d;

	(void)av;
	(void)d;
	if (ac == 2 && ft_isdigit(av[1][0]) && !av[1][1])
	{
/*		print_usage(ac);
		if (!(d = main_frac(ft_atoi(av[1]))))
			return (1);
		mlx_hook(d->win, 2, 1, key_hook, d);
		mlx_hook(d->win, 4, 4, mouse_hook, d);
		mlx_hook(d->win, 6, 16, mouse_hook_move, d);
		mlx_expose_hook(d->win, expose_hook, d);
		mlx_loop(d->mlx);*/
	}
//	else
//		print_usage(1);
	return (0);
}
