/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 22:30:46 by yberries          #+#    #+#             */
/*   Updated: 2020/08/08 15:19:02 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	look_around(t_board *map, int dist)
{
	if (map->x > 0 && map->y > 0 && map->heat[map->x - 1][map->y - 1] == -1)
		map->heat[map->x - 1][map->y - 1] = dist + 1;
	if (map->x > 0 && map->heat[map->x - 1][map->y] == -1)
		map->heat[map->x - 1][map->y] = dist + 1;
	if (map->x > 0 && (map->y + 1) < map->width && \
				map->heat[map->x - 1][map->y + 1] == -1)
		map->heat[map->x - 1][map->y + 1] = dist + 1;
	if (map->y > 0 && map->heat[map->x][map->y - 1] == -1)
		map->heat[map->x][map->y - 1] = dist + 1;
	if ((map->y + 1) < map->width && map->heat[map->x][map->y + 1] == -1)
		map->heat[map->x][map->y + 1] = dist + 1;
	if (map->y > 0 && (map->x + 1) < map->height && \
				map->heat[map->x + 1][map->y - 1] == -1)
		map->heat[map->x + 1][map->y - 1] = dist + 1;
	if ((map->x + 1) < map->height && map->heat[map->x + 1][map->y] == -1)
		map->heat[map->x + 1][map->y] = dist + 1;
	if ((map->x + 1) < map->height && (map->y + 1) < map->width && \
			map->heat[map->x + 1][map->y + 1] == -1)
		map->heat[map->x + 1][map->y + 1] = dist + 1;
}

static void	fill_heat(t_board *map)
{
	int dist;

	dist = 0;
	while (dist < map->height || dist < map->width)
	{
		map->x = -1;
		while (++map->x < map->height)
		{
			map->y = -1;
			while (++map->y < map->width)
				if (map->heat[map->x][map->y] == dist)
					look_around(map, dist);
		}
		++dist;
	}
}

void		start_heat(t_board *map, t_piece *piece, t_res *res)
{
	int i;

	fill_heat(map);
	get_res(map, piece, res);
	i = -1;
	while (++i < map->height)
		free(map->heat[i]);
	ft_memdel((void **)&map->heat);
}
