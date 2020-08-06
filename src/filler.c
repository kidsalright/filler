/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 05:25:17 by yberries          #+#    #+#             */
/*   Updated: 2020/08/06 20:38:22 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

static void	free_data(t_board *map, t_piece *piece)
{
	int	i;

	i = -1;
	while (++i < map->height)
		ft_strdel(&map->map[i]);
	ft_memdel((void **)(&map->map));
	i = 0;
	while (i < piece->height)
		ft_strdel(&piece->p[i++]);
	ft_memdel((void **)(&piece->p));
}

static void	find_player(t_board *map)
{
	char	*line;

	line = NULL;
	map->plr = 0;
	while (get_next_line(0, &line))
	{
		if (line && ft_strstr(line, "$$$ exec") && \
				ft_strstr(line, "yberries.filler"))
		{
			if (ft_strstr(line, "p1"))
				map->plr = 'O';
			else if (ft_strstr(line, "p2"))
				map->plr = 'X';
		}
		ft_strdel(&line);
		if (map->plr)
			break;
	}
	map->enm = (map->plr = 'O') ? 'X' : 'O';
}

static void	output_res(t_res res)
{
	ft_putnbr(res.x);
	write(1, " ", 1);
	ft_putnbr(res.y);
	write(1, "\n", 1);
}

int	main(void)
{
	t_piece		piece;
	t_board		map;
	t_res		res;

	find_player(&map);
	while (1)
	{
		input_parse(&map, &piece);
		get_res(&map, &piece, &res);
		output_res(res);
		free_data(&map, &piece);
	}
	return (0);
}
