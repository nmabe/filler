/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmaxlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 10:40:39 by nmabe             #+#    #+#             */
/*   Updated: 2018/06/30 10:53:47 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strmaxlen(const char **str)
{
	size_t	len;
	int		i;
	int		row;

	i = 0;
	len = ft_strlen(str[i]);
	row = sizeof(str);
	while (i < row)
	{
		if (ft_strlen(str[i]) < ft_strlen(str[i + 1]))
			len = ft_strlen(str[i + 1]);
		i++;
	}
	return (len);
}
