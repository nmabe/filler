/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:47:14 by nmabe             #+#    #+#             */
/*   Updated: 2018/06/30 12:11:48 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			dlen;
	char			*pdest;
	const char		*psrc;

	pdest = (char *)ft_memchr(dest, '\0', size);
	if (pdest == NULL)
		return (size + ft_strlen(src));
	psrc = src;
	dlen = (size_t)(pdest - dest) + ft_strlen(psrc);
	while ((size_t)(pdest - dest) < size - 1 && *psrc != '\0')
	{
		*pdest = *psrc;
		pdest++;
		psrc++;
	}
	*pdest = '\0';
	return (dlen);
}
