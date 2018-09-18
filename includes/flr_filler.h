/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 10:51:18 by nmabe             #+#    #+#             */
/*   Updated: 2018/08/19 10:37:03 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLR_FILLER_H
# define FLR_FILLER_H
# define BUFF_SIZE 32
# include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_game
{
	int			board_x;
	int			board_y;
	int			player;
	char		cow;
	int			token_x;
	int			token_y;
	int			start_row;
	int			movable;
	int			f_l;
	int			end;
	char		**board;
	char		**token;
}				t_game;

int				get_next_line(const int fd, char **line);
int				flr_play_filler(t_game *filler);
int				flr_play_pos(int x, int y, int r);
void			flr_getboard(t_game *filler);
void			flr_middle_left(t_game *filler);
void			flr_bottom_right(t_game *filler);
void			flr_top_left(t_game *filler);
void			flr_getstart(t_game *filler);
int				flr_get_pos(t_game *filler, int x, int y);
void			flr_f_l(t_game *filler);

#endif
