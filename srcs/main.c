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
#include "keymap.h"

int		hook_func(int x, int y, t_env *env)
{
	env->x = x;
	env->y = y;
	if (env->fl == 1 && env->x <= env->wsize && env->x >= 0
		&& env->y <= env->wsize && env->y >= 0)
		ft_strequ(env->filename, "julia") ? movejulia(env) : 0;
	return (0);
}

int		key_func(int key, t_env *env)
{
	ft_strequ(env->filename, "julia") ? check_julia(env, key) : 0;
	ft_strequ(env->filename, "mandel") ? check_mandel(env, key) : 0;
	ft_strequ(env->filename, "burnship") ? check_burnship(env, key) : 0;
	if (key == 4)
		env->fl *= -1;
	if (key == 53)
	{
		ft_putstr("Exit program\n");
		exit(1);
	}
	return (0);
}

int		mouse_func(int click, int x, int y, t_env *env)
{
	int		a;

	click == 1 ? env->fl = 1 : 0;
	if (click == SCROLL_DOWN)
	{
		env->zx = env->zx + (env->zx - x) / 5;
		env->zy = env->zy + (env->zy - y) / 5;
		env->zoom += env->zoom / 5;
	}
	if (click == SCROLL_UP)
	{
		env->zx = env->zx - (env->zx - x) / 5;
		env->zy = env->zy - (env->zy - y) / 5;
		env->zoom -= env->zoom / 5;
	}
	env->img = mlx_new_image(env->mlx, env->wsize, env->wsize);
	ft_strequ(env->filename, "julia") ? ft_julia(env) : 0;
	ft_strequ(env->filename, "mandel") ? ft_mandel(env) : 0;
	ft_strequ(env->filename, "burnship") ? ft_burnship(env) : 0;
	a = mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env		env;
	int			a;

	if (argc != 2)
	{
		ft_putstr("mandel\njulia\nburnship\nfish\ntrees\n");
		exit(1);
	}
	env.zoom = 1;
	env.fl = -1;
	env.filename = ft_strdup(argv[1]);
	env.iter = 50;
	env.wsize = 500;
	env.zx = env.wsize >> 1;
	env.zy = env.wsize >> 1;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.wsize, env.wsize, "fractol");
	env.img = mlx_new_image(env.mlx, env.wsize, env.wsize);
	a = mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	mlx_hook(env.win, 2, 0, key_func, &env);
	mlx_hook(env.win, 4, 0, mouse_func, &env);
	mlx_hook(env.win, 6, 0, hook_func, &env);
	mlx_destroy_image(env.mlx, env.img);
	mlx_loop(env.mlx);
	return (0);
}
