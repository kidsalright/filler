/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_res.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 22:30:46 by yberries          #+#    #+#             */
/*   Updated: 2020/08/06 20:42:39 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_res(t_board *map, t_piece *piece, t_res *res)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while(j < map->width)
		{
			if (map->plr == map->map[i][j])
			{
				res->x = 8;
				res->y = 2;
			}
			++j;
		}
		++i;
	}
}
