/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_get_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 09:59:43 by nmabe             #+#    #+#             */
/*   Updated: 2018/08/19 10:31:49 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/flr_filler.h"

static void		flr_gettoken(t_game *filler)
{
	int			i;
	char		*line;
	char		*line_br;

	i = 0;
	line_br = "\0";
	get_next_line(0, &line);
	filler->token_x = ft_atoi(&line[6]);
	filler->token_y = ft_atoi(&line[8]);
	while (get_next_line(0, &line) > 0)
	{
		line_br = ft_strjoin(line_br, line);
		line_br = ft_strcat(line_br, "|");
		i++;
		if (i == filler->token_x)
			break ;
	}
	filler->token = ft_strsplit(line_br, '|');
	free(line_br);
}

void			flr_getstart(t_game *filler)
{
	int			x;
	int			y;

	x = (filler->board_x / 2) + (filler->board_x / 10);
	y = 0;
	while (y < filler->board_y)
	{
		if (filler->board[x][y] == 'X')
		{
			filler->start_row = x;
			break ;
		}
		y++;
	}
}

void			flr_getboard(t_game *filler)
{
	char		*line;
	char		*line_br;
	int			i;

	i = 0;
	line_br = "\0";
	while (get_next_line(0, &line) > 0)
	{
		if (line && ft_isdigit(line[0]))
		{
			line_br = ft_strjoin(line_br, &line[4]);
			line_br = ft_strcat(line_br, "|");
			i++;
		}
		if (i == filler->board_x)
			break ;
	}
	filler->board = ft_strsplit(line_br, '|');
	free(line_br);
	flr_gettoken(filler);
}
