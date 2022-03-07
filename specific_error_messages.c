/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_error_messages.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:26:39 by cerdelen          #+#    #+#             */
/*   Updated: 2022/03/07 17:26:39 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	no_surrounding_wall(char a)
{
	if (a != '1')
	{
		write(2, "Map is not entirely surrounded by Walls!\n", 41);
		exit(EXIT_SUCCESS);
	}
}

void	non_rectangular_map(void)
{
	write(2, "Map has no rectangular Shape!\n", 30);
	exit(EXIT_SUCCESS);
}

void	check_interior(char a)
{
	if (a != '0' && a != '1' && a != 'C' && a != 'E' && a != 'P')
	{
		write(2, "Map includes unknown character!\n", 32);
		exit(EXIT_SUCCESS);
	}
}
