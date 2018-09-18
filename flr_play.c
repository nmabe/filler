/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 14:59:30 by nmabe             #+#    #+#             */
/*   Updated: 2018/08/19 10:31:01 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/flr_filler.h"

static int		flr_check_column(t_game *filler, int x, int col, char c)
{
	int			i;

	i = 0;
	while (i < x)
	{
		if (filler->board[i][col] == c)
			return (1);
		i++;
	}
	return (0);
}

static int		flr_check_row(t_game *filler, int row, int y, char c)
{
	int			i;

	i = 0;
	while (i < y)
	{
		if (filler->board[row][i] == ft_tolower(c)
				|| filler->board[row][i] == ft_toupper(c))
			return (1);
		i++;
	}
	return (0);
}

static int		flr_check_tok(t_game *filler)
{
	int			x;
	int			y;

	x = filler->board_x - 1;
	while (x >= 0)
	{
		y = filler->board_y - 1;
		while (y >= 0)
		{
			if (flr_check_row(filler, x, y, 'o') == 1)
				return (1);
			if (flr_check_row(filler, x, y, 'x') == 1)
				return (1);
			y--;
		}
		x--;
	}
	return (0);
}

static void		flr_getpart(int *col, int *col1, int *row, t_game *filler)
{
	int			x;
	int			y;

	x = filler->board_x;
	y = filler->board_y;
	*col = flr_check_column(filler, x, y - 1, filler->cow);
	*col1 = flr_check_column(filler, x, 0, filler->cow);
	*row = flr_check_row(filler, filler->start_row, y, 'o');
}

int				flr_play_filler(t_game *filler)
{
	int			ccol;
	int			ccol1;
	int			crow;
	int			last;

	flr_getboard(filler);
	flr_getstart(filler);
	flr_getpart(&ccol, &ccol1, &crow, filler);
	last = flr_check_tok(filler);
	flr_f_l(filler);
	if (ccol == 0 && ccol1 == 0 && crow == 1 && last == 0)
		flr_middle_left(filler);
	else if (filler->f_l == 0 && last == 1)
		flr_bottom_right(filler);
	else
		flr_bottom_right(filler);
	if (filler->movable == 1)
		flr_top_left(filler);
	if (filler->end == 1)
		return (flr_play_pos(0, 0, 0));
	return (1);
}
