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

void	zoom_in(t_env *env)
{
	env->mid_x = env->mid_x + (env->mid_x - env->mouse_x) / 5;
	env->mid_y = env->mid_y + (env->mid_y - env->mouse_y) / 5;
	env->zoom += env->zoom / 5;
}

void	zoom_out(t_env *env)
{
	env->mid_x = env->mid_x - (env->mid_x - env->mouse_x) / 5;
	env->mid_y = env->mid_y - (env->mid_y - env->mouse_y) / 5;
	env->zoom -= env->zoom / 5;
}
