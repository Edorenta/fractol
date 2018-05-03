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

void	ft_draw_pixel(int x, int y, unsigned short *bgr, t_env *env)
{
	int		a;

	if (x <= 0 || y <= 0 || x >= env->wsize || y >= env->wsize)
		return ;
	env->bpp = 0;
	env->sizeline = 0;
	env->endian = 0;
	env->imbuf = mlx_get_data_addr(env->img, &env->bpp,
	&env->sizeline, &env->endian);
	a = (y * (env->sizeline >> 2) + x) << 2;
	env->imbuf[a] = bgr[0];
	env->imbuf[a + 1] = bgr[1];
	env->imbuf[a + 2] = bgr[2];
}

void	drawing(t_env *env, int i, int x, int y)
{
	env->bgr[0] = 0;
	env->bgr[1] = (i * 4) % 255;
	env->bgr[2] = (i * 4) % 255;
	env->cfl == 'g' ? ft_swap(&env->bgr[0], &env->bgr[1]) : 0;
	env->cfl == 'r' ? ft_swap(&env->bgr[0], &env->bgr[2]) : 0;
	ft_draw_pixel(x, y, env->bgr, fr);
}
