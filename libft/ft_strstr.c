/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:47:53 by nmabe             #+#    #+#             */
/*   Updated: 2018/06/30 09:30:22 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	size_t		j;
	size_t		f;
	char		*ret;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	ret = (char *)haystack;
	while (haystack[i] != '\0')
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			f = i;
			while (haystack[f++] == needle[j++])
			{
				if (needle[j] == '\0')
					return (ret);
			}
		}
		ret++;
		i++;
	}
	return (NULL);
}
