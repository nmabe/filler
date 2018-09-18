/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:52:55 by nmabe             #+#    #+#             */
/*   Updated: 2018/06/30 10:23:15 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	temp = (*alst);
	while ((*alst) != NULL)
	{
		temp = (*alst);
		(*alst) = (*alst)->next;
		del(temp->content, temp->content_size);
		free(temp);
	}
	(*alst) = NULL;
}
