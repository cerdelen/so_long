/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:26:22 by cerdelen          #+#    #+#             */
/*   Updated: 2022/03/07 17:26:22 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arg_number(int argc)
{
	if (argc < 2)
		write(2, "No Inputfile!\n", 14);
	if (argc < 2)
		exit(EXIT_SUCCESS);
	if (argc > 3)
		write(2, "Too many Arguments!\n", 14);
	if (argc > 3)
		exit(EXIT_SUCCESS);
}

//Returns 1 if it is a .ber file, 0 if not
int	is_ber_file(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (len < 5)
		return (0);
	if (map[len - 1] != 'r')
		return (0);
	if (map[len - 2] != 'e')
		return (0);
	if (map[len - 3] != 'b')
		return (0);
	if (map[len - 4] != '.')
		return (0);
	return (1);
}

void	check_file(char *file)
{
	int	fd;

	if (!is_ber_file(file))
	{
		write(2, "The File is no .ber File!\n", 26);
		exit(EXIT_SUCCESS);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror(file);
	if (fd < 0)
		exit(EXIT_SUCCESS);
	close(fd);
}

void	set_up_data(data_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	map_data->colls = 0;
	while (i < map_data->rows)
	{
		j = 0;
		while (j < map_data->columns)
		{
			if (map_data->map[i][j] == 'C')
				map_data->colls++;
			if (map_data->map[i][j] == 'P')
				map_data->player_pos[0] = j;
			if (map_data->map[i][j] == 'P')
				map_data->player_pos[1] = i;
			j++;
		}
		i++;
	}
	j = 0;
}

char	**check_input(int argc, char **argv, data_map *map_data)
{
	int		rows;
	int		columns;
	char	**map;

	check_arg_number(argc);
	check_file(argv[1]);
	columns = get_columns(argv[1]);
	rows = get_rows(argv[1]);
	map = create_map(argv[1], rows, columns);
	map_data->columns = columns;
	map_data->rows = rows;
	map_data->map = map;
	set_up_data(map_data);
	return (map);
}
