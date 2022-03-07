/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:26:31 by cerdelen          #+#    #+#             */
/*   Updated: 2022/03/07 17:26:32 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_vars *vars)
{
	int	p[2];

	p[0] = vars->map_data.player_pos[0];
	p[1] = vars->map_data.player_pos[1];
	if (vars->map_data.colls > 0 && (vars->map_data.map[(p[1])
				- 1][p[0]] == 'E'))
		return (0);
	if (vars->map_data.map[(p[1]) - 1][p[0]] == '1')
		return (0);
	if (vars->map_data.map[(p[1]) - 1][p[0]] == 'C')
		vars->map_data.colls--;
	if (vars->map_data.map[(p[1]) - 1][p[0]] == 'E')
		close_game(vars);
	vars->map_data.map[p[1]][p[0]] = '0';
	vars->map_data.map[(p[1]) - 1][p[0]] = 'P';
	vars->map_data.player_pos[1]--;
	vars->map_data.moves++;
	return (0);
}

int	move_left(t_vars *vars)
{
	int	p[2];

	p[0] = vars->map_data.player_pos[0];
	p[1] = vars->map_data.player_pos[1];
	if (vars->map_data.colls > 0 && (vars->map_data.map[p[1]][(p[0])
			- 1] == 'E'))
		return (0);
	if (vars->map_data.map[p[1]][(p[0]) - 1] == '1')
		return (0);
	if (vars->map_data.map[p[1]][(p[0]) - 1] == 'C')
		vars->map_data.colls--;
	if (vars->map_data.map[p[1]][(p[0]) - 1] == 'E')
		close_game(vars);
	vars->map_data.map[p[1]][p[0]] = '0';
	vars->map_data.map[p[1]][(p[0]) - 1] = 'P';
	vars->map_data.player_pos[0]--;
	vars->map_data.moves++;
	return (0);
}

int	move_down(t_vars *vars)
{
	int	p[2];

	p[0] = vars->map_data.player_pos[0];
	p[1] = vars->map_data.player_pos[1];
	if (vars->map_data.colls > 0 && (vars->map_data.map[(p[1])
				+ 1][p[0]] == 'E'))
		return (0);
	if (vars->map_data.map[(p[1]) + 1][p[0]] == '1')
		return (0);
	if (vars->map_data.map[(p[1]) + 1][p[0]] == 'C')
		vars->map_data.colls--;
	if (vars->map_data.map[(p[1]) + 1][p[0]] == 'E')
		close_game(vars);
	vars->map_data.map[p[1]][p[0]] = '0';
	vars->map_data.map[(p[1]) + 1][p[0]] = 'P';
	vars->map_data.player_pos[1]++;
	vars->map_data.moves++;
	return (0);
}

int	move_right(t_vars *vars)
{
	int	p[2];

	p[0] = vars->map_data.player_pos[0];
	p[1] = vars->map_data.player_pos[1];
	if (vars->map_data.colls > 0 && (vars->map_data.map[p[1]][(p[0])
			+ 1] == 'E'))
		return (0);
	if (vars->map_data.map[p[1]][(p[0]) + 1] == '1')
		return (0);
	if (vars->map_data.map[p[1]][(p[0]) + 1] == 'C')
		vars->map_data.colls--;
	if (vars->map_data.map[p[1]][(p[0]) + 1] == 'E')
		close_game(vars);
	vars->map_data.map[p[1]][p[0]] = '0';
	vars->map_data.map[p[1]][(p[0]) + 1] = 'P';
	vars->map_data.player_pos[0]++;
	vars->map_data.moves++;
	return (0);
}
