/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:38:01 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/29 13:43:30 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	size_t i;
	size_t size;

	size = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[size] != '\0')
	{
		s1[i + size] = s2[size];
		size++;
	}
	s1[i + size] = '\0';
	return (s1);
}
