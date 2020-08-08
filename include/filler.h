/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 05:36:31 by yberries          #+#    #+#             */
/*   Updated: 2020/08/08 07:41:55 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdio.h>

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
	int	height;
	int	width;
	int	x;
	int	y;
	char	**map;
}		t_board;

int	input_parse(t_board *map, t_piece *piece);
void	get_res(t_board *map, t_piece *piece, t_res *res);

#endif
