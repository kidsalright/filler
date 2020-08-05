/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 05:36:31 by yberries          #+#    #+#             */
/*   Updated: 2020/08/05 11:51:03 by yberries         ###   ########.fr       */
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
	char	**piece;
	int	height;
	int	width;
}		t_piece;

typedef struct	s_board
{
	char	plr;
	char	enm;
	char	**board;
	int	height;
	int	width;
	char	**heat;
}		t_board;

void	get_board(t_board *map);
void	get_piece(t_piece *piece);
void	get_res(t_board *map, t_piece *piece, t_res *res);

#endif
