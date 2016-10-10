#include "rt.h"

static void		print_usage(void)
{
	tt_pl("Usage: ./rt [scene]");
}

int				main(int ac, char **av)
{
	t_data	*d;

	d = NULL;
	(void)av;
	if (ac == 2)
	{
		d = (t_data *)init();
		draw(d);
		mlx_expose_hook(d->win, expose_hook, d);
		mlx_hook(d->win, 2, 1, key_hook, d);
		mlx_loop(d->mlx);
	}
	else
		print_usage();
	return (0);
}
