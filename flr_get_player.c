/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_get_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 14:58:48 by nmabe             #+#    #+#             */
/*   Updated: 2018/08/19 10:29:56 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/flr_filler.h"

static int		flr_right(t_game *filler, int x, int y)
{
	int			i;
	int			j;

	i = filler->token_x - 1;
	while (i >= 0)
	{
		j = filler->token_y - 1;
		while (j >= 0)
		{
			if (filler->token[i][j] == '*')
				if (flr_get_pos(filler, y - j, x - i) == 1)
					return (flr_play_pos(x - i, y - j, 1));
			j--;
		}
		i--;
	}
	return (0);
}

static int		flr_left(t_game *filler, int x, int y)
{
	int			i;
	int			j;

	i = 0;
	while (i < filler->token_x)
	{
		j = 0;
		while (j < filler->token_y)
		{
			if (filler->token[i][j] == '*')
			{
				if (flr_get_pos(filler, y - j, x - i) == 1)
					return (flr_play_pos(x - i, y - j, 1));
			}
			j++;
		}
		i++;
	}
	return (0);
}

void			flr_top_left(t_game *filler)
{
	int			x;
	int			y;

	x = 0;
	while (x < filler->board_x)
	{
		y = 0;
		while (y < filler->board_y)
		{
			if (filler->board[x][y] == filler->cow)
				if (flr_right(filler, x, y) == 1)
					return ;
			y++;
		}
		x++;
	}
}

void			flr_middle_left(t_game *filler)
{
	int			x;
	int			y;
	int			r;
	int			r1;

	r = filler->start_row / 10;
	r1 = filler->start_row / 11;
	x = filler->start_row + r - r1;
	while (x < filler->start_row + r + r1)
	{
		y = 0;
		while (y < filler->board_y)
		{
			if (filler->board[x][y] == filler->cow)
				if (flr_right(filler, x, y) == 1)
					return ;
			y++;
		}
		x++;
	}
	filler->movable = 1;
}

void			flr_bottom_right(t_game *filler)
{
	int			x;
	int			y;

	x = filler->board_x - 1;
	while (x > 0)
	{
		y = filler->board_y - 1;
		while (y > 0)
		{
			if (filler->board[x][y] == filler->cow)
			{
				if (flr_left(filler, x, y) == 1)
					return ;
			}
			y--;
		}
		x--;
	}
	filler->end = 1;
}
