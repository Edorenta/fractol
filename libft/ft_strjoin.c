/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 19:32:44 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/09 14:40:01 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	buf = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (buf == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		buf[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		buf[i] = s2[j];
		j++;
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
