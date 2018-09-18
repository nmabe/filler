/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:47:32 by nmabe             #+#    #+#             */
/*   Updated: 2018/06/30 09:34:09 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *str, int c)
{
	char		*s;
	size_t		i;
	size_t		len;

	i = 0;
	s = (char *)str;
	len = ft_strlen(str);
	while (i <= len)
	{
		if (str[i] == c)
			return (s);
		i++;
		s++;
	}
	return (NULL);
}
