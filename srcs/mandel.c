/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:20:44 by pde-rent          #+#    #+#             */
/*   Updated: 2018/02/23 18:18:26 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	plot_mandel(t_env *env)
{
	env->y = -1;
	while (++env->y < env->height)
	{
		env->x = -1;
		while (++env->x < env->width)
		{
			env->cr = 2.5 * (env->x - env->mid_x) /
			((env->width / 2) * env->zoom) - 0.73 + env->move_x;
			env->cim = (env->y - env->mid_y) /
				(0.5 * (env->height / 2) * env->zoom) + env->move_y;
			env->newr = 0;
			env->newim = 0;
			env->i = -1;
			while (++env->i < env->it)
			{
				env->oldr = env->newr;
				env->oldim = env->newim;
				env->newr = env->oldr * env->oldr - env->oldim * env->oldim + env->cr;
				env->newim = 2 * env->oldr * env->oldim + env->cim;
				if (env->newim * env->newim + env->newr * env->newr > 4)
					break ;
			}
			sketch(env, env->i, env->x, env->y);
		}
	}
}

void	up_mandel(t_env *env)
{
	filltab(env->img_tab, BLACK, env->width * env->height);
	plot_mandel(env);
	display_imgtab(env);
}
