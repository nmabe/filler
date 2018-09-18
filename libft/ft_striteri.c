/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:15:51 by nmabe             #+#    #+#             */
/*   Updated: 2018/06/30 12:42:02 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	int		i;

	i = 0;
	if (!str || !f)
		return ;
	while (str[i] != '\0')
	{
		f(i, &str[i]);
		i++;
	}
}
