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

typedef struct		s_env
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
}					t_env;

char				*ft_strdup(char *src);
size_t				slen(char *s);
void				ft_putstr(char *s);
void				ft_swap(unsigned short *a, unsigned short *b);
int					ft_strequ(const char *s1, const char *s2);
double				f_abs(double f);
void				drawing(t_env *env, int i, int x, int y);

void				check_burnship(t_env *env, int key);
void				ft_burnship(t_env *env);
void				moveburnship(t_env *env);
void				check_mandel(t_env *env, int key);
void				ft_mandel(t_env *env);
void				movemandel(t_env *env);\
void				check_julia(t_env *env, int key);
void				ft_julia(t_env *env);
void				movejulia(t_env *env);
void				ft_draw_pixel(int x, int y,
								unsigned short *bgr, t_env *env);
void				ft_fish(t_env *env);
void				check_fish(t_env *env, int key);
void				ft_trees(t_env *env);
void				check_trees(t_env *env, int key);

#endif
