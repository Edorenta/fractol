/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:30:27 by pde-rent          #+#    #+#             */
/*   Updated: 2018/02/24 14:07:02 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					mouse_hook(int x, int y, t_env *env)
{
	env->mouse_x = x;
	env->mouse_y = y;
	if (env->fl == 1 && env->mouse_x < env->width && env->mouse_x >= 0
		&& env->mouse_y < env->height && env->mouse_y >= 0)
		IS_SET_JULIA ? up_julia(env) : 0;
	return (0);
}

int					key_hook(int key_code, t_env *env)
{
	key_code == KEY_NUM6 ? zoom_in(env) : 0;
	key_code == KEY_NUM9 ? zoom_out(env) : 0;
	key_code == KEY_H ? env->fl *= -1 : 0;
	key_code == KEY_ADD ? env->it += 1 : 0;
	key_code == KEY_SUBTRACT ? env->it -= 1 : 0;
	key_code == KEY_LEFT ? env->move_x += 0.1 : 0;
	key_code == KEY_RIGHT ? env->move_x -= 0.1 : 0;
	key_code == KEY_DOWN ? env->move_y -= 0.1 : 0;
	key_code == KEY_UP ? env->move_y += 0.1 : 0;
	(key_code == KEY_PERIOD && env->min_iter >= 0) ? env->min_iter-- : 0;
	(key_code == KEY_COMMA && env->min_iter <= env->it) ? env->min_iter++ : 0;
	key_code == KEY_C ? env->clr_shift++ : 0;
	key_code == KEY_R ? env->clr_range++ : 0;
	key_code == KEY_O ? env->opacity++ : 0;
	if (key_code == KEY_ESCAPE)
	{
		pstr("Exit program\n");
		exit(1);
	}
	IS_SET_JULIA ? up_julia(env) : 0;
	IS_SET_MANDEL ? up_mandel(env) : 0;
	IS_SET_BSHIP ? up_burnship(env) : 0;
	return (0);
}

int					mouse_sc_realoll_hook(int key_code, int x, int y, t_env *env)
{
	env->mouse_x = x;
	env->mouse_y = y;
	key_code == LEFT_CLICK ? env->fl = 1 : 0;
	key_code == SCROLL_DOWN ? zoom_in(env) : 0;
	key_code == SCROLL_UP ? zoom_out(env) : 0;
	IS_SET_JULIA ? plot_julia(env) : 0;
	IS_SET_MANDEL ? plot_mandel(env) : 0;
	IS_SET_BSHIP ? plot_burnship(env) : 0;
	display_imgtab(env);
	return (0);
}

static inline int	compliant_av(t_env *env, int ac, char **av)
{
	int		i;

	i = 0;
	env->selection = 0;
	while (++i < ac)
		if (eq(av[i], "julia") || eq(av[i], "-julia") ||
			eq(av[i], "Julia") || eq(av[i], "-Julia") || eq(av[i], "1"))
			SWITCH_JULIA;
		else if (eq(av[i], "mandel") || eq(av[i], "-mandel") ||
			eq(av[i], "Mandel") || eq(av[i], "-Mandel") || eq(av[i], "2"))
			SWITCH_MANDEL;
		else if (eq(av[i], "burnship") || eq(av[i], "-burnship") ||
			eq(av[i], "Burnship") || eq(av[i], "-Burnship") || eq(av[i], "3"))
			SWITCH_BSHIP;
		else
			return (0);
	env->min_iter = 7;
	env->clr_shift = 0;
	env->clr_range = 0;
	env->opacity = 0;
	return (1);
}

int					main(int ac, char **av)
{
	t_env		env;

	if (ac < 2 || ac > 4 || !compliant_av(&env, ac, av))
	{
		pstr("Options:\n\t-Mandel\t\t(1)\n\t-Julia\t\t(2)\n\t-Burnship\t(3)\n");
		exit(1);
	}
	if (ac > 2)
	{
		(env.selection & (1 << 0)) ? system("./fractol -julia") : 0;
		(env.selection & (1 << 1)) ? system("./fractol -mandel") : 0;
		(env.selection & (1 << 2)) ? system("./fractol -burnship") : 0;
		return (0);
	}
	env.zoom = 1;
	env.fl = -1;
	env.it = 50;
	env.width = 1400;
	env.height = 850;
	env.mid_x = env.width / 2;
	env.mid_y = env.height / 2;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.width, env.height, "Fractol");
	env.img = mlx_new_image(env.mlx, env.width, env.height);
	mlx_hook(env.win, 2, 0, key_hook, &env);
	mlx_hook(env.win, 4, 0, mouse_sc_realoll_hook, &env);
	mlx_hook(env.win, 6, 0, mouse_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
