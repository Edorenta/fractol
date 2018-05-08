/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:28:04 by pde-rent          #+#    #+#             */
/*   Updated: 2018/02/23 17:59:16 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ppixel(int x, int y, int clr, t_env *env)
{
	if (x <= 0 || y <= 0 || x >= env->width || y >= env->height)
		return ;
	env->bpp = 0;
	env->sizeline = 0;
	env->endian = 0;
	env->img_tab = (int *)mlx_get_data_addr(env->img, &env->bpp,
		&env->sizeline, &env->endian);
	env->img_tab[env->width * y + x] = clr;
}

void	sketch(t_env *env, int i, int x, int y)
{
	change_clr(env, i);
	ppixel(x, y, env->clr, env);
}
