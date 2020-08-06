/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 05:36:31 by yberries          #+#    #+#             */
/*   Updated: 2020/08/06 17:30:09 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct	s_res
{
	int	x;
	int	y;
}		t_res;

typedef struct	s_piece
{
	char	**p;
	int	height;
	int	width;
}		t_piece;

typedef struct	s_board
{
	char	plr;
	char	enm;
	int	height;
	int	width;
	char	**map;
	int	**heat;
}		t_board;

void	input_parse(t_board *map, t_piece *piece);
void	get_res(t_board *map, t_piece *piece, t_res *res);

#endif
