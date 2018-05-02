/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:24:48 by pde-rent          #+#    #+#             */
/*   Updated: 2017/12/01 19:33:01 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		j;
	char		*buf;

	j = 0;
	if (!s || !(buf = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len--)
		buf[j++] = s[start++];
	buf[j] = '\0';
	return (buf);
}
