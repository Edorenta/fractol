/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:05:28 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/30 17:46:53 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	check;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return ((char*)big);
	while (big[i] && i <= len)
	{
		check = i;
		while (little[j] == big[i] && little[j] && i < len)
		{
			j++;
			i++;
		}
		if (j == ft_strlen(little))
			return ((char*)&big[i - j]);
		j = 0;
		i = check + 1;
	}
	return (NULL);
}
