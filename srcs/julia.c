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

void	plot_julia(t_env *env)
{
	int		i;

	env->y = -1;
	while (++env->y < env->height)
	{
		env->x = -1;
		while (++env->x < env->width)
		{
			env->newr = 2.5 * (env->x - env->mid_x) /
			((env->width / 2) * env->zoom) + env->move_x;
			env->newim = (env->y - env->mid_y) /
			((env->height / 2) * env->zoom) + env->move_y;
			i = -1;
			while (++i < env->it)
			{
				env->oldr = env->newr;
				env->oldim = env->newim;
				env->newr = env->oldr * env->oldr - env->oldim * env->oldim + env->cr;
				env->newim = 2 * env->oldr * env->oldim + env->cim;
				if (env->newim * env->newim + env->newr * env->newr > 4)
					break ;
			}
			sketch(env, i, env->x, env->y);
		}
	}
}

void	up_julia(t_env *env)
{
	if (env->fl == 1)
	{
		env->cr = (double)env->mouse_x / env->width * 4 - 2;
		env->cim = (double)env->mouse_y / env->height * 4 - 2;
	}
	filltab(env->img_tab, BLACK, env->width * env->height);
	plot_julia(env);
	display_imgtab(env);
}
