/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 05:25:17 by yberries          #+#    #+#             */
/*   Updated: 2020/08/08 16:15:32 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	free_data(t_board *map, t_piece *piece)
{
	int i;

	i = -1;
	while (++i < map->height)
		ft_strdel(&map->map[i]);
	ft_memdel((void **)(&map->map));
	i = -1;
	while (++i < piece->height)
		ft_strdel(&piece->p[i]);
	ft_memdel((void **)(&piece->p));
}

static int	find_player(t_board *map)
{
	char *line;

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
			ft_strdel(&line);
			return (1);
		}
		ft_strdel(&line);
	}
	return (0);
}

static void	output_res(t_res res)
{
	ft_putnbr(res.x);
	write(1, " ", 1);
	ft_putnbr(res.y);
	write(1, "\n", 1);
}

int			main(void)
{
	t_piece	piece;
	t_board	map;
	t_res	res;

	if (find_player(&map))
	{
		while (input_parse(&map, &piece))
		{
			start_heat(&map, &piece, &res);
			output_res(res);
			free_data(&map, &piece);
		}
	}
	return (0);
}
