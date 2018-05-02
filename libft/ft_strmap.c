/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:49:00 by pde-rent          #+#    #+#             */
/*   Updated: 2017/12/05 18:36:25 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*buf;

	if (!s || !(f))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	buf = (char*)malloc(sizeof(char) * (i + 1));
	if (!buf)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		buf[i] = f(s[i]);
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
