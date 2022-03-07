/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:26:36 by cerdelen          #+#    #+#             */
/*   Updated: 2022/03/07 17:26:37 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_and_exit(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->map_data.rows)
	{
		free(vars->map_data.map[i]);
		i++;
	}
	free(vars->map_data.map);
	exit(EXIT_SUCCESS);
}

int	close_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_and_exit(vars);
	return (0);
}

int	key_press(int key, t_vars *vars)
{
	if (key == 13)
		move_up(vars);
	if (key == 0)
		move_left(vars);
	if (key == 1)
		move_down(vars);
	if (key == 2)
		move_right(vars);
	if (key == 53)
		close_game(vars);
	render_map(vars);
	return (0);
}

void	game_function(t_vars vars)
{
	vars.map_data.moves = 0;
	vars.mlx = mlx_init();
	get_images(&vars.game_images, vars.mlx, &vars);
	vars.win = mlx_new_window(vars.mlx, (vars.game_images.widht
				* vars.map_data.columns), (vars.game_images.height
				* vars.map_data.rows), "so_long");
	render_map(&vars);
	mlx_key_hook(vars.win, key_press, &vars);
	mlx_hook(vars.win, 17, 0, close_game, &vars);
	mlx_loop(vars.mlx);
}
