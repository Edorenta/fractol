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

#ifndef UNISTD_H
# include <unistd.h>
#endif
#ifndef STDLIB_H
# include <stdlib.h>
#endif

double	f_abs(double f)
{
	return (f < 0.0 ? -f : f);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = (char*)malloc(sizeof(*str) * (len + 1));
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}

size_t		slen(char *s)
{
	return (*s ? slen(++s) + 1 : 0);
}

void	pstr(char *s)
{
	write(1, s, slen(s));
}

void	ft_swap(unsigned short *a, unsigned short *b)
{
	unsigned short c;

	c = *a;
	*a = *b;
	*b = c;
}

int		eq(const char *s1, const char *s2)
{
	int		i;

	if (s1 && s2)
	{
		i = -1;
		while (s1[++i])
			if (s1[i] != s2[i])
				return (0);
		return (1);
	}
	return (0);
}