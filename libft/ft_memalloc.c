/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:13:40 by nmabe             #+#    #+#             */
/*   Updated: 2018/06/30 09:51:46 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*ret;

	ret = (void *)malloc(sizeof(*ret) * size);
	if (size == 0 || ret == NULL)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
