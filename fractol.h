/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:54:20 by pde-rent          #+#    #+#             */
/*   Updated: 2018/02/24 13:50:56 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "libft/libft.h"

typedef struct		s_fract
{
	int					i;
	int					cy;
	int					cx;
	double				zx;
	double				zy;
	char				cfl;
	short				key;
	int					iter;
	short				fl;
	char				*filename;
	char				*imbuf;
	unsigned short		bgr[3];
	int					bpp;
	int					sizeline;
	int					endian;
	int					wsize;
	void				*mlx;
	void				*img;
	void				*win;
	int					x;
	int					y;
	double				cr;
	double				cim;
	double				newr;
	double				newim;
	double				oldr;
	double				oldim;
	double				movex;
	double				movey;
	double				zoom;
}					t_fract;

void				drawing(t_fract *fr, int i, int x, int y);
void				check_burnship(t_fract *fr, int key);
void				ft_burnship(t_fract *fr);
void				moveburnship(t_fract *fr);
void				ft_swap(unsigned short *a, unsigned short *b);
void				check_mandel(t_fract *fr, int key);
void				check_julia(t_fract *fr, int key);
void				ft_draw_pixel(int x, int y,
								unsigned short *bgr, t_fract *fr);
void				ft_julia(t_fract *fr);
void				ft_fish(t_fract *fr);
void				check_fish(t_fract *fr, int key);
void				ft_trees(t_fract *fr);
void				check_trees(t_fract *fr, int key);
void				movejulia(t_fract *fr);
void				ft_mandel(t_fract *fr);
void				movemandel(t_fract *fr);

#endif
