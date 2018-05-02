/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:51:04 by pde-rent          #+#    #+#             */
/*   Updated: 2017/12/01 19:41:47 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	while (*alst)
	{
		tmp = *alst;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = tmp->next;
	}
	*alst = NULL;
}
