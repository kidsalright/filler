/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 05:25:17 by yberries          #+#    #+#             */
/*   Updated: 2020/08/05 16:12:36 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

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
			{
				ft_strdel(&line);
				map->plr = 'O';
			}
			else if (ft_strstr(line, "p2"))
			{
				ft_strdel(&line);
				map->plr = 'X';
			}
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
		get_board(&map);
	//	get_piece(&piece);
	//	get_res(&map, &piece, &res);
	//	output_res(res);
	}
	return (0);
}
