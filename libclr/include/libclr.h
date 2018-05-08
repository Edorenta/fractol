/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 03:50:38 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 15:51:23 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCLR_H
# define LIBCLR_H

# include <stdlib.h>
# include <math.h>

# define DMIN(X,Y)		(X > Y ? Y : X)
# define DMAX(X,Y)		(X > Y ? X : Y)

# define MODE_RGB		1
# define MODE_RGBA		2
# define MODE_ARGB		3

# define WHITE			0x00FFFFFF
# define GREY			0x00A4A4A4
# define LIGHT_GREY		0x00CCCCCC
# define CYAN			0x0000FFFF
# define RED			0x00FF0000
# define GREEN			0x0000FF00
# define SKY_BLUE		0x0000CCFF
# define BLUE			0x000000FF
# define MAGENTA		0x00FF00FF
# define YELLOW			0x00FFFF00
# define SAND			0x00FFCC66
# define ORANGE			0x00FF8000

# define BLACK			0x00000000
# define DARK_GREY		0x00232323
# define DARK_CYAN		0x00001a1e
# define DARK_RED		0x00140000
# define DARK_GREEN		0x00002105
# define DARK_BLUE		0x0000114c
# define DARK_PINK		0x0010001c
# define DARK_SAND		0x00261d00
# define DARK_FUN		0x006D647F
# define BROWN			0x001c1515

# define ALPHA_100		0xFF
# define ALPHA_95		0xF2
# define ALPHA_90		0xE6
# define ALPHA_85		0xD9
# define ALPHA_80		0xCC
# define ALPHA_75		0xBF
# define ALPHA_70		0xB3
# define ALPHA_65		0xA6
# define ALPHA_60		0x99
# define ALPHA_55		0x8C
# define ALPHA_50		0x80
# define ALPHA_45		0x73
# define ALPHA_40		0x66
# define ALPHA_35		0x59
# define ALPHA_30		0x4D
# define ALPHA_25		0x40
# define ALPHA_20		0x33
# define ALPHA_15		0x26
# define ALPHA_10		0x1A
# define ALPHA_5		0x0D
# define ALPHA_0		0x00

# define RED0 0x00fdebe8
# define RED1 0x00f8c2ba
# define RED2 0x00f39a8c
# define RED3 0x00ee715e
# define RED4 0x00e94830
# define RED5 0x00cf2f16
# define RED6 0x00a12411
# define RED7 0x00731a0c
# define RED8 0x00451007
# define RED9 0x00170502
# define BLUE0 0x00e9f6fc
# define BLUE1 0x00bce5f6
# define BLUE2 0x008fd3f0
# define BLUE3 0x0062c2ea
# define BLUE4 0x0035b0e4
# define BLUE5 0x001b97ca
# define BLUE6 0x0015759d
# define BLUE7 0x000f5470
# define BLUE8 0x00093243
# define BLUE9 0x00031116
# define PINK0 0x00fee6fb
# define PINK1 0x00fdb5f3
# define PINK2 0x00fb84ea
# define PINK3 0x00f952e2
# define PINK4 0x00f821da
# define PINK5 0x00de07c0
# define PINK6 0x00ad0696
# define PINK7 0x007b046b
# define PINK8 0x004a0240
# define PINK9 0x00190115
# define GRE0 0x00edfbea
# define GRE1 0x00c8f2bf
# define GRE2 0x00a4ea95
# define GRE3 0x007fe16a
# define GRE4 0x005bd940
# define GRE5 0x0041bf26
# define GRE6 0x0033951e
# define GRE7 0x00246a15
# define GRE8 0x0016400d
# define GRE9 0x00071504

long	parse_long(char *str);
double	parse_double(char *str);
int		parse_rgb(char *str);
int		rgb_to_hex(int r, int g, int b);
int		rgba_to_hex(int r, int g, int b, int a);
int		argb_to_hex(int a, int r, int g, int b);
int		shade_color(int clr, int pct);
int		shade_opacity(int clr, int pct, int mode);
int		blend_color(int clr1, int clr2, int pct);
int		set_opacity(int clr, int lvl);
int		hex_r(long clr, int mode);
int		hex_g(long clr, int mode);
int		hex_b(long clr, int mode);
int		hex_a(long clr, int mode);
int		*hex_rgba(long clr, int mode, int *ptr);

#endif
