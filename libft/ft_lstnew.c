/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:52:34 by nmabe             #+#    #+#             */
/*   Updated: 2018/06/30 10:22:27 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*copy;

	copy = (t_list*)malloc(sizeof(*copy));
	if (copy == NULL || content == NULL || content_size == 0)
	{
		if (copy == NULL)
			return (NULL);
		else
		{
			copy->content = NULL;
			copy->content_size = 0;
		}
	}
	else
	{
		if ((copy->content = (void *)malloc(sizeof(content_size))) == NULL)
			return (NULL);
		copy->content_size = content_size;
		copy->content = ft_memcpy(copy->content, content, content_size);
	}
	copy->next = NULL;
	return (copy);
}
