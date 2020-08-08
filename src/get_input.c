/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:42:03 by yberries          #+#    #+#             */
/*   Updated: 2020/08/08 06:55:33 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	piece_parse(t_piece *piece)
{
	char	*line;
	int	i;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Piece"))
		{
			piece->height = ft_atoi(ft_strchr(line, ' '));
			piece->width = ft_atoi(ft_strrchr(line, ' '));
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
	i = -1;
	piece->p = (char **)malloc(sizeof(char *) * piece->height);
	while (++i < piece->height && get_next_line(0, &line))
	{
		piece->p[i] = ft_strnew(piece->width);
		piece->p[i] = ft_strncpy(piece->p[i], line, piece->width);
		ft_strdel(&line);
	}
}

static void	board_parse(t_board *map, t_piece *piece)
{
	char	*line;
	char	*skip;
	int	i;

	line = NULL;
	i = -1;
	skip = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	map->map = (char **)malloc(sizeof(char *) * map->height);
	while (++i < map->height && get_next_line(0, &line))
	{
		skip = line;
		while (*skip && !ft_strchr(".xXoO", *skip))
			++skip;
		map->map[i] = ft_strnew(map->width);
		ft_strncpy(map->map[i], skip, map->width);
		ft_strdel(&line);
	}
}

int		input_parse(t_board *map, t_piece *piece)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Plateau"))
		{
			map->height = ft_atoi(ft_strchr(line, ' '));
			map->width = ft_atoi(ft_strrchr(line, ' '));
			ft_strdel(&line);
			board_parse(map, piece);
			piece_parse(piece);
			return (1);
		}
		ft_strdel(&line);
	}
	return (0);
}
