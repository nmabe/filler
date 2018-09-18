/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 14:58:30 by nmabe             #+#    #+#             */
/*   Updated: 2018/08/19 10:31:24 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/flr_filler.h"

static void		flr_init_filler(t_game *filler)
{
	filler->player = 0;
	filler->board_x = 0;
	filler->board_y = 0;
	filler->start_row = 0;
	filler->token_x = 0;
	filler->token_y = 0;
	filler->cow = '-';
	filler->end = 0;
	filler->movable = 0;
	filler->f_l = 0;
}

void			flr_f_l(t_game *filler)
{
	int			y;

	y = 0;
	while (y < filler->board_y)
	{
		if (filler->board[0][y] == filler->cow)
		{
			filler->f_l = 1;
			return ;
		}
		if (filler->board[filler->board_x - 1][y] == filler->cow)
		{
			filler->f_l = 1;
			return ;
		}
		y++;
	}
	filler->f_l = 0;
}

int				flr_play_pos(int x, int y, int r)
{
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putendl("\0");
	return (r);
}

int				main(void)
{
	char		*line;
	t_game		filler;

	flr_init_filler(&filler);
	get_next_line(0, &line);
	filler.player = ft_atoi(&line[10]);
	filler.cow = (filler.player == 2) ? 'X' : 'O';
	get_next_line(0, &line);
	filler.board_x = ft_atoi(&line[8]);
	filler.board_y = ft_atoi(&line[11]);
	while (1)
	{
		if (filler.player == 1 || filler.player == 2)
		{
			if (flr_play_filler(&filler) == 0)
				break ;
		}
	}
	return (0);
}
