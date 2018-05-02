/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smykyten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:40:08 by smykyten          #+#    #+#             */
/*   Updated: 2018/01/06 16:11:09 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;

	mem = (char*)malloc(sizeof(char) * size);
	if (mem)
	{
		while (size)
		{
			mem[size - 1] = '\0';
			size--;
		}
		return (mem);
	}
	return (NULL);
}
