/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:12:44 by pde-rent          #+#    #+#             */
/*   Updated: 2018/02/23 18:21:00 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	plot_burnship(t_env *env)
{
	env->y = -1;
	while (++env->y < env->height)
	{
		env->x = -1;
		while (++env->x < env->width)
		{
			env->c_real = 3 * (env->x - env->mid_x) /
			((env->width / 2) * env->zoom) + env->move_x;
			env->c_imaginary = 1.8 * (env->y - env->mid_y) /
			((env->height / 2) * env->zoom) + env->move_y;
			env->new_real = 0;
			env->new_imaginary = 0;
			env->i = -1;
			while (++env->i < env->it)
			{
				env->prev_real = env->new_real;
				env->prev_imaginary = env->new_imaginary;
				env->new_real = env->prev_real * env->prev_real - env->prev_imaginary * env->prev_imaginary + env->c_real;
				env->new_imaginary = f_abs(2 * env->prev_real * env->prev_imaginary) + env->c_imaginary;
				if (env->new_imaginary * env->new_imaginary + env->new_real * env->new_real > 4)
					break ;
			}
			sketch(env, env->i, env->x, env->y);
		}
	}
}

void	up_burnship(t_env *env)
{
	filltab(env->img_tab, BLACK, env->width * env->height);
	plot_burnship(env);
	display_imgtab(env);
}
