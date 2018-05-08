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
# include <mlx.h>
# include <stdlib.h>
# ifndef KEYMAP_H
#  include "keymap.h"
# endif
# ifndef LIBCLR_H
#  include "libclr.h"
# endif

# define SWITCH_JULIA	(env->selection ^= (1 << 0))
# define SWITCH_MANDEL	(env->selection ^= (1 << 1))
# define SWITCH_BSHIP	(env->selection ^= (1 << 2))
# define IS_SET_JULIA	(env->selection & (1 << 0))
# define IS_SET_MANDEL	(env->selection & (1 << 1))
# define IS_SET_BSHIP	(env->selection & (1 << 2))

# define JULIA			0
# define MANDEL			1
# define BSHIP			2

typedef struct		s_env
{
	int					i;
	int					mouse_y;
	int					mouse_x;
	double				mid_x;
	double				mid_y;
	short				key_code;
	int					it;
	short				fl;
	int					*img_tab;
	int					clr;
	int					clr_shift;
	int					bpp;
	int					selection;
	int					sizeline;
	int					endian;
	int					width;
	int					height;
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
	double				move_x;
	double				move_y;
	double				zoom;
}					t_env;

void				zoom_in(t_env *env);
void				zoom_out(t_env *env);
void				ppixel(int x, int y, int clr, t_env *env);
int					change_clr(t_env *env, int i);
int 		     	display_imgtab(t_env *env);
void				filltab(int *tab, int clr, int size);
char				*ft_strdup(char *src);
size_t				slen(char *s);
void				pstr(char *s);
void				ft_swap(unsigned short *a, unsigned short *b);
int					eq(const char *s1, const char *s2);
double				f_abs(double f);
void				sketch(t_env *env, int i, int x, int y);
int					nb_set_bits(int i);

void				plot_burnship(t_env *env);
void				up_burnship(t_env *env);

void				plot_mandel(t_env *env);
void				up_mandel(t_env *env);

void				plot_julia(t_env *env);
void				up_julia(t_env *env);

#endif
