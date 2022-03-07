/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:26:13 by cerdelen          #+#    #+#             */
/*   Updated: 2022/03/07 17:26:13 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror(file);
	if (fd < 0)
		exit(EXIT_SUCCESS);
	return (fd);
}

int	get_columns(char *file)
{
	char	*line;
	int		columns;
	int		fd;

	columns = 0;
	fd = open_fd(file);
	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Empty file!\n", 13);
		exit(EXIT_SUCCESS);
	}
	columns = ft_strlen(line) - 1;
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
	return (columns - 1);
}

int	get_rows(char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open_fd(file);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

char	**create_map(char *file, int rows, int columns)
{
	char	**map;
	char	*line;
	int		i;
	int		j;
	int		fd;

	map = malloc(sizeof(char *) * rows);
	fd = open_fd(file);
	i = 0;
	j = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	check_validity(map, rows, columns);
	return (map);
}
