/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:39:40 by yberries          #+#    #+#             */
/*   Updated: 2020/08/05 16:10:23 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	create_piece(t_piece *piece)
{
	int	i;

	piece->piece = (char**)malloc(sizeof(char*) * piece->height);
	i = 0;
	while (i < piece->height)
	{
		piece->piece[i] = ft_strnew(piece->width);
		++i;
	}
}

static void	read_coords(t_piece *piece, char *line)
{
	int		i;

	i = 0;
	while (line[i] && !ft_isdigit(line[i]))
		++i;
	piece->height = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		++i;
	while (line[i] && !ft_isdigit(line[i]))
		++i;
	piece->width = ft_atoi(line + i);
}

static void	fill_piece(t_piece *piece)
{
	int	i;
	char	*line;

	line = NULL;
	i = 0;
	while (i < piece->height)
	{
		get_next_line(0, &line);
		if (line)
		{
			if (ft_strlen(line) == piece->width)
				ft_strcpy(piece->piece[i], line);
			ft_strdel(&line);
		}
		++i;
	}
}

void		get_piece(t_piece *piece)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Piece") != NULL)
		{
			read_coords(piece, line);
			create_piece(piece);
			if (line)
				ft_strdel(&line);
			fill_piece(piece);
		}
		ft_strdel(&line);
	}
}
