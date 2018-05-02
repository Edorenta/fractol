/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:01:55 by pde-rent          #+#    #+#             */
/*   Updated: 2017/12/05 18:36:14 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*buf;

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
		buf[i] = f(i, s[i]);
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
