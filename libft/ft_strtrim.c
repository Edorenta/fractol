/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:11:37 by pde-rent          #+#    #+#             */
/*   Updated: 2017/12/01 21:05:39 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	int		countend;
	int		countbeg;
	char	*buf;

	if (!s)
		return (NULL);
	countend = ft_strlen(s) - 1;
	countbeg = 0;
	i = 0;
	while (s[countbeg] == ' ' || s[countbeg] == '\t' || s[countbeg] == '\n')
		countbeg++;
	while (s[countend] == ' ' || s[countend] == '\t' || s[countend] == '\n')
		countend--;
	if (countend - countbeg < 0)
		buf = (char*)malloc(sizeof(char) * 1);
	else
	{
		if (!(buf = (char*)malloc(sizeof(char) * countend - countbeg + 2)))
			return (NULL);
		while (countbeg <= countend)
			buf[i++] = s[countbeg++];
	}
	buf[i] = '\0';
	return (buf);
}
