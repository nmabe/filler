/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:14:36 by nmabe             #+#    #+#             */
/*   Updated: 2018/06/30 09:54:29 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	str = (void *)ft_memalloc(sizeof(*str) * size + 1);
	if (str == NULL)
		return (NULL);
	str = (char *)ft_memset(str, '\0', size);
	return (str);
}
