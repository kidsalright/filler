/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_placing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:39:40 by yberries          #+#    #+#             */
/*   Updated: 2020/08/08 15:23:18 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	can_place(t_board *map, t_piece *piece, int x, int y)
{
	int	i;
	int	j;
	int	can;

	i = -1;
	can = 0;
	if ((piece->height + x) > map->height || \
			(piece->width + y) > map->width)
		return (0);
	while (++i < piece->height)
	{
		j = -1;
		while (++j < piece->width)
		{
			if (piece->p[i][j] == '*' && \
				ft_toupper(map->map[x + i][y + j]) == map->plr)
				++can;
			else if (piece->p[i][j] == '*' && \
				map->map[x + i][y + j] != '.')
				return (0);
			if (can > 1)
				return (0);
		}
	}
	return ((can == 1) ? 1 : 0);
}

static int	best_sum(t_board *map, t_piece *piece, int x, int y)
{
	int	i;
	int	j;
	int	sum;

	i = -1;
	sum = 0;
	while (++i < piece->height)
	{
		j = -1;
		while (++j < piece->width)
			if (piece->p[i][j] == '*')
				sum += map->heat[i + x][j + y];
	}
	return (sum);
}

void		get_res(t_board *map, t_piece *piece, t_res *res)
{
	int	x;
	int	y;
	int	sum;

	x = -1;
	res->y = 0;
	res->x = 0;
	sum = 2147483647;
	while (++x < map->height)
	{
		y = -1;
		while (++y < map->width)
			if (can_place(map, piece, x, y))
				if (best_sum(map, piece, x, y) < sum)
				{
					res->y = y;
					res->x = x;
					sum = best_sum(map, piece, x, y);
				}
	}
}
