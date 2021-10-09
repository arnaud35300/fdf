/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:44:42 by arguilla          #+#    #+#             */
/*   Updated: 2021/10/09 01:28:25 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	count_numbers(int *xmax, char *line)
{
	char	*endptr;
	int		err;

	*xmax = 0;
	while (line && *line)
	{
		ft_strtol(line, &endptr, 10, &err);
		line = endptr;
		while (ft_isspace(*line))
			line++;
		(*xmax)++;
	}
}

static void	get_numbers(t_fdf *f, int i, char *line)
{
	char	*endptr;
	int		err;
	int		j;

	j = -1;
	while (line && *line)
	{
		f->matrix[i][++j].z = ft_strtol(line, &endptr, 10, &err);
		f->matrix[i][j].y = i;
		f->matrix[i][j].x = j;
		line = endptr;
		while (ft_isspace(*line))
			line++;
	}
}

static int	get_matrix_size(int *xmax, int *ymax, int fd)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		count_numbers(xmax, line);
		free(line);
		(*ymax)++;
	}
	if (line)
		free(line);
	return (1);
}

static int	init_matrix(t_fdf *f, int fd)
{
	char	*line;
	int		i;

	i = -1;
	f->matrix = malloc(sizeof(t_dot *) * f->ymax);
	if (!f->matrix)
		return (0);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		f->matrix[++i] = malloc(sizeof(t_dot) * f->xmax);
		if (!f->matrix[i])
		{
			free(line);
			exit(free_struct(f, 0));
		}
		get_numbers(f, i, line);
		free(line);
	}
	if (line)
		free(line);
	return (1);
}

int	parse_map(t_fdf *f, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	f->ymax = 0;
	f->xmax = 0;
	if (!get_matrix_size(&(f->xmax), &(f->ymax), fd))
		return (0);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	return (init_matrix(f, fd));
}
