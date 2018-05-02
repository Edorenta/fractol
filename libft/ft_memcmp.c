/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smykyten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:34:06 by smykyten          #+#    #+#             */
/*   Updated: 2017/11/25 16:42:22 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char x1;
	unsigned char x2;

	while (n)
	{
		x1 = *(unsigned char*)s1;
		x2 = *(unsigned char*)s2;
		if (x1 != x2)
			return (x1 - x2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
