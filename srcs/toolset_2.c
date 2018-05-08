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

static	int	clr[60] = {
    BLACK, LIGHT_GREY, ORANGE, DARK_FUN, CYAN,
    MAGENTA, SAND, YELLOW, SKY_BLUE, GREEN,
    RED0, RED1, RED2, RED3, RED4, RED5, RED6, RED7, RED8, RED9,
    BLUE0, BLUE1, BLUE2, BLUE3, BLUE4, BLUE5, BLUE6, BLUE7, BLUE8, BLUE9,
    PINK0, PINK1, PINK2, PINK3, PINK4, PINK5, PINK6, PINK7, PINK8, PINK9,
    GRE0, GRE1, GRE2, GRE3, GRE4, GRE5, GRE6, GRE7, GRE8, GRE9};

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
    return (1);
}

int		change_clr(t_env *env, int i)
{
    int picker;

    picker = (env->clr_range % 5) * 10 + ((i + env->clr_shift) % 10);
	env->clr = i > env->min_iter ? clr[picker] : BLACK;
    i == env->it ? env->clr = BLACK : 0;
    set_opacity(env->clr, env->opacity % 22);
	return (1);
}
