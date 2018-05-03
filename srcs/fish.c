/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fish.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 13:40:44 by pde-rent          #+#    #+#             */
/*   Updated: 2018/02/24 13:49:43 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fish(t_env *env)
{
	while (++env->cy < env->wsize)
	{
		env->cx = -1;
		while (++env->cx < env->wsize)
		{
			env->cr = (env->cx - env->zx) /
				((env->wsize >> 1) * env->zoom) + env->movex;
			env->cim = (env->cy - env->zy) /
				((env->wsize >> 1) * env->zoom) + env->movey;
			env->newr = 0;
			env->newim = 0;
			env->i = -1;
			while (++env->i < env->iter)
			{
				env->oldr = env->newr;
				env->oldim = env->newim;
				env->newr = f_abs(env->oldr *
				env->oldr - env->oldim * env->oldim) + env->cr;
				env->newim = 2 * env->oldr * env->oldim + env->cim;
				if (env->newim * env->newim + env->newr * env->newr > 4)
					break ;
			}
			drawing(env, env->i, env->cx, env->cy);
		}
	}
}

void	check_fish(t_env *env, int key)
{
	int		a;

	env->img = mlx_new_image(env->mlx, env->wsize, env->wsize);
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
	ft_fish(env);
	a = mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
}
