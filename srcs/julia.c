/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:55:10 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/10 13:44:48 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_env *env)
{
	int		i;

	env->cy = -1;
	while (++env->cy < env->wsize)
	{
		env->cx = -1;
		while (++env->cx < env->wsize)
		{
			env->newr = 1.5 * (env->cx - env->zx) /
			((env->wsize >> 1) * env->zoom) + env->movex;
			env->newim = (env->cy - env->zy) /
			((env->wsize >> 1) * env->zoom) + env->movey;
			i = -1;
			while (++i < env->iter)
			{
				env->oldr = env->newr;
				env->oldim = env->newim;
				env->newr = env->oldr * env->oldr - env->oldim * env->oldim + env->cr;
				env->newim = 2 * env->oldr * env->oldim + env->cim;
				if (env->newim * env->newim + env->newr * env->newr > 4)
					break ;
			}
			drawing(env, i, env->cx, env->cy);
		}
	}
}

void	check_julia(t_env *env, int key)
{
	key == 24 ? env->iter += 10 : 0;
	key == 27 ? env->iter -= 10 : 0;
	key == 123 ? env->movex += 0.1 : 0;
	key == 124 ? env->movex -= 0.1 : 0;
	key == 125 ? env->movey -= 0.1 : 0;
	key == 126 ? env->movey += 0.1 : 0;
	if (key == 18)
	{
		env->cfl = 'g';
		env->key = key;
	}
	if (key == 19)
	{
		env->cfl = 'r';
		env->key = key;
	}
	if (env->key != 19 && env->key != 18)
		env->cfl = 'b';
	movejulia(env);
}

void	movejulia(t_env *env)
{
	int		a;

	env->cr = (double)env->x / env->wsize * 4 - 2;
	env->cim = (double)env->y / env->wsize * 4 - 2;
	env->img = mlx_new_image(env->mlx, env->wsize, env->wsize);
	ft_julia(env);
	a = mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
}
