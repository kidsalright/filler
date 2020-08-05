/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:42:03 by yberries          #+#    #+#             */
/*   Updated: 2020/08/05 16:11:10 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "stdio.h"

static void	create_map(t_board *map)
{
	int	i;

	i = 0;
	map->board = (char**)malloc(sizeof(char*) * map->height);
	while (i < map->height)
	{
		map->board[i] = ft_strnew(map->width);
		++i;
	}
}

static void	read_coords(char *line, t_board *map)
{
	int	i;

	i = 0;
	while (line[i] && !ft_isdigit(line[i]))
		++i;
	map->height = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		++i;
	while (line[i] && !ft_isdigit(line[i]))
		++i;
	map->width = ft_atoi(line + i);
}

static void	fill_map(t_board *map)
{
	int	i;
	int	j;
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	if (line)
		ft_strdel(&line);
	i = 0;
	while (i < map->height)
	{
		get_next_line(0, &line);
		if (line)
		{
			j = 0;
			while (line[j] && !ft_isspace(line[j]))
				++j;
			if (ft_strlen(line + j + 1) <= map->width)
				ft_strcpy(map->board[i], line + j + 1);
			ft_strdel(&line);
		}
		++i;
	}
}

void		get_board(t_board *map)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Plateau") != NULL)
		{
			read_coords(line, map);
			create_map(map);
			if (line)
				ft_strdel(&line);
			fill_map(map);
		}
	}
}
