/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:15:35 by nmabe             #+#    #+#             */
/*   Updated: 2018/06/30 12:44:04 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_striter(char *str, void (*f)(char *))
{
	int		i;

	i = 0;
	if (!str || !f)
		return ;
	while (str[i] != '\0')
	{
		f(&str[i]);
		i++;
	}
}