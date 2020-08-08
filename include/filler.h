/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 05:36:31 by yberries          #+#    #+#             */
/*   Updated: 2020/08/08 16:18:22 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct	s_res
{
	int			x;
	int			y;
}				t_res;

typedef struct	s_piece
{
	int			height;
	int			width;
	char		**p;
}				t_piece;

typedef struct	s_board
{
	int			height;
	int			width;
	int			x;
	int			y;
	int			**heat;
	char		**map;
	char		plr;
}				t_board;

int				input_parse(t_board *map, t_piece *piece);
void			start_heat(t_board *map, t_piece *piece, t_res *res);
void			get_res(t_board *map, t_piece *piece, t_res *res);

#endif
