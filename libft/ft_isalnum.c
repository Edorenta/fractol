/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:12:33 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/26 14:44:11 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int character)
{
	if ((character >= 65 && character <= 90) ||
		(character >= 97 && character <= 122) ||
		(character <= 57 && character >= 48))
		return (1);
	else
		return (0);
}
