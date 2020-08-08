/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_res.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 22:30:46 by yberries          #+#    #+#             */
/*   Updated: 2020/08/08 07:45:58 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			calc_res(t_board *map, int **hmap, int res)
{
	if (map->x > 0 && map->y > 0 && hmap[map->x - 1][map->y - 1] == -1)
		hmap[map->x - 1][map->y - 1] = res + 1;
	if (map->x > 0 && hmap[map->x - 1][map->y] == -1)
		hmap[map->x - 1][map->y] = res + 1;
	if (map->x > 0 && (map->y + 1) < map->width && \
			hmap[map->x - 1][map->y + 1] == -1)
		hmap[map->x - 1][map->y + 1] = res + 1;
	if (map->y > 0 && hmap[map->x][map->y - 1] == -1)
		hmap[map->x][map->y - 1] = res + 1;
	if ((map->y + 1) < map->width && hmap[map->x][map->y + 1] == -1)
		hmap[map->x][map->y + 1] = res + 1;
	if (map->y > 0 && (map->x + 1) < map->height && \
			hmap[map->x + 1][map->y - 1] == -1)
		hmap[map->x + 1][map->y - 1] = res + 1;
	if ((map->x + 1) < map->height && hmap[map->x + 1][map->y] == -1)
		hmap[map->x + 1][map->y] = res + 1;
	if ((map->x + 1) < map->height && (map->y + 1) \
			< map->width && hmap[map->x + 1][map->y + 1] == -1)
		hmap[map->x + 1][map->y + 1] = res + 1;
}

static void			calc_heat(t_board *map, int **hmap)
{
	int				res;

	res = 0;
	map->x = 0;
	while (res < map->height || res < map->width)
	{
		map->x = 0;
		while (map->x < map->height)
		{
			map->y = 0;
			while (map->y < map->width)
			{
				if (hmap[map->x][map->y] == res)
					calc_res(map, hmap, res);
				++map->y;
			}
			++map->x;
		}
		++res;
	}
}

static int	**init_heat(t_board *map)
{
	int	**heat;
	int	i;
	int	j;

	i = -1;
	heat = (int **)malloc(sizeof(int *) * map->height);
	while (++i < map->height)
	{
		heat[i] = (int *)malloc(sizeof(int) * map->width);
		j = -1;
		while (++j < map->width)
		{
			if (map->plr != ft_toupper(map->map[i][j]) && map->map[i][j] != '.')
				heat[i][j] = 0;
			else
				heat[i][j] = -1;
		}
	}
	return (heat);
}

void	print_heat(t_board *map, int **hmap)
{
	int	i = -1;
	int	j;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			printf("%3d", hmap[i][j]);
		printf("\n");
	}
}

void		get_res(t_board *map, t_piece *piece, t_res *res)
{
	int	**hmap;

	hmap = init_heat(map);
	calc_heat(map, hmap);
	print_heat(map, hmap);
	res->x = 0;
	res->y = 0;
}
