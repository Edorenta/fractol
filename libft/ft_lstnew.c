/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:51:34 by pde-rent          #+#    #+#             */
/*   Updated: 2017/12/01 18:45:13 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
	if (!content)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
		return (tmp);
	}
	if (tmp)
	{
		tmp->content = malloc(content_size);
		tmp->content = ft_memcpy(tmp->content, content, content_size);
		tmp->next = NULL;
		tmp->content_size = content_size;
		return (tmp);
	}
	else
		return (NULL);
}
