/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_extract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:55:10 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/10 13:44:48 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int 	nb_set_bits(int i)
{
     i = i - ((i / 2) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

void	filltab(int *tab, int clr, int size)
{
    static int i;

    i = -1;
    while (++i < size)
        tab[i] = clr;
}

int		display_imgtab(t_env *env)
{
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
    //filltab(env->img_tab, BLACK, env->width * env->height);
    return (1);
}

int		change_clr(t_env *env, int i)
{
	static	int	clr[10] = {BLACK, LIGHT_GREY, ORANGE, DARK_FUN, CYAN,
		MAGENTA, SAND, YELLOW, SKY_BLUE, GREEN};
	env->clr = i > 7 ? clr[(i + env->clr_shift) % 10] : BLACK;
    i == env->it ? env->clr = BLACK : 0;
	return (1);
}
