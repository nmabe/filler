/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:43:12 by nmabe             #+#    #+#             */
/*   Updated: 2018/06/30 09:15:04 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_memmcpy(void *dest, const void *src, size_t n)
{
	char		*pdest;
	char		*psrc;

	if (n == 0 || dest == src)
		return (dest);
	pdest = (char *)dest;
	psrc = (char *)src;
	while (n--)
	{
		pdest[n] = psrc[n];
	}
	return ((void *)pdest);
}

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
		ft_memcpy(dest, src, n);
	if (dest > src)
		ft_memmcpy(dest, src, n);
	return (dest);
}
