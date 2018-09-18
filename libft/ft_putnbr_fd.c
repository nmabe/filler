/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:20:02 by nmabe             #+#    #+#             */
/*   Updated: 2018/06/30 10:30:56 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = (long)n;
	if (n < 0)
	{
		nbr = nbr * (-1);
		ft_putchar_fd('-', fd);
	}
	if (nbr > 9)
	{
		ft_putnbr_fd((nbr / 10), fd);
		nbr = (nbr % 10);
	}
	ft_putchar_fd(nbr + '0', fd);
}
