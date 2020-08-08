/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:42:03 by yberries          #+#    #+#             */
/*   Updated: 2020/08/08 15:25:29 by yberries         ###   ########.fr       */
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

static void	board_parse(t_board *m)
{
	char	*line;
	char	*skip;
	int	i;
	int	j;

	line = NULL;
	i = -1;
	skip = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	m->map = (char **)malloc(sizeof(char *) * m->height);
	m->heat = (int **)malloc(sizeof(int *) * m->height);
	while (++i < m->height && get_next_line(0, &line))
	{
		skip = line;
		while (*skip && !ft_strchr(".xXoO", *skip))
			++skip;
		m->map[i] = ft_strdup(skip);
		m->heat[i] = (int *)malloc(sizeof(int) * m->width);
		j = -1;
		while (++j < m->width)
			m->heat[i][j] = ((m->plr != ft_toupper(m->map[i][j]) \
					&& m->map[i][j] != '.') ? (0) : (-1));
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
			board_parse(map);
			piece_parse(piece);
			return (1);
		}
		ft_strdel(&line);
	}
	return (0);
}
