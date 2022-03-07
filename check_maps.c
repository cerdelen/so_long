/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:26:07 by cerdelen          #+#    #+#             */
/*   Updated: 2022/03/07 17:27:31 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangular_shape(char **map, int rows, int columns)
{
	int		i;
	int		j;
	char	check;

	i = 0;
	while (i < (rows - 1))
	{
		j = ft_strlen(map[i]);
		map[i][j - 1] = 0;
		i++;
		if (j != (columns + 2))
			non_rectangular_map();
	}
	j = ft_strlen(map[i]);
	if (j != columns)
		non_rectangular_map();
}

void	check_amount_of_extra_fields(int *different_tiles)
{
	if (different_tiles[0] == 0)
	{
		write(2, "There is no starting Position for the Player!\n", 46);
		exit(EXIT_SUCCESS);
	}
	if (different_tiles[0] > 1)
	{
		write(2, "There are more than one starting Positions for the Player!\n",
			59);
		exit(EXIT_SUCCESS);
	}
	if (different_tiles[1] == 0)
	{
		write(2, "There is no map exit!\n", 22);
		exit(EXIT_SUCCESS);
	}
	if (different_tiles[2] < 1)
	{
		write(2, "There is no collectible on the Map!\n", 36);
		exit(EXIT_SUCCESS);
	}
}

void	check_all_necessities(char **map, int rows, int columns)
{
	int	different_tiles[3];
	int	i;
	int	j;

	i = 0;
	different_tiles[0] = 0;
	different_tiles[1] = 0;
	different_tiles[2] = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			if (map[i][j] == 'P')
				different_tiles[0]++;
			else if (map[i][j] == 'E')
				different_tiles[1]++;
			else if (map[i][j] == 'C')
				different_tiles[2]++;
			j++;
		}
		i++;
	}
	check_amount_of_extra_fields(different_tiles);
}

void	check_validity(char **map, int rows, int columns)
{
	int	i;
	int	j;

	i = 0;
	check_rectangular_shape(map, rows, columns);
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			if (i == 0 || i == rows - 1)
				no_surrounding_wall(map[i][j]);
			else if (j == 0 || j == columns - 1)
				no_surrounding_wall(map[i][j]);
			else
				check_interior(map[i][j]);
			j++;
		}
		i++;
	}
	check_all_necessities(map, rows, columns);
}
