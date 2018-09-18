/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_check_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 14:59:12 by nmabe             #+#    #+#             */
/*   Updated: 2018/08/19 10:32:54 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/flr_filler.h"

static int		flr_check_pos(t_game *filler, int x, int y)
{
	int			i;
	int			j;
	int			tmp;
	int			cnt;

	i = -1;
	tmp = x;
	cnt = 0;
	while (++i < filler->token_x && y < filler->board_x)
	{
		j = -1;
		x = tmp;
		while (++j < filler->token_y && filler->board_y)
		{
			if (filler->player == 1)
				if (filler->board[y][x] == 'O' && filler->token[i][j] == '*')
					cnt++;
			if (filler->player == 2)
				if (filler->token[i][j] == '*' && filler->board[y][x] == 'X')
					cnt++;
			x++;
		}
		y++;
	}
	return ((cnt > 1) ? 0 : 1);
}

static int		flr_check_opos(t_game *filler, int x, int y)
{
	int			i;
	int			j;
	int			tmp;

	i = 0;
	tmp = x;
	while (i < filler->token_x && y < filler->board_x)
	{
		j = 0;
		x = tmp;
		while (j < filler->token_y && x < filler->board_y)
		{
			if (filler->player == 1)
				if (filler->token[i][j] == '*' && filler->board[y][x] == 'X')
					return (0);
			if (filler->player == 2)
				if (filler->token[i][j] == '*' && filler->board[y][x] == 'O')
					return (0);
			x++;
			j++;
		}
		i++;
		y++;
	}
	return (1);
}

int				flr_get_pos(t_game *filler, int x, int y)
{
	if (y > filler->board_x || y < 0)
		return (0);
	if (x > filler->board_y || x < 0)
		return (0);
	if (y + filler->token_x > filler->board_x)
		return (0);
	if (x + filler->token_y > filler->board_y)
		return (0);
	if (flr_check_pos(filler, x, y) == 0)
		return (0);
	if (flr_check_opos(filler, x, y) == 0)
		return (0);
	return (1);
}
