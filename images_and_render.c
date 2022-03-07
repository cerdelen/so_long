/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_and_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:26:24 by cerdelen          #+#    #+#             */
/*   Updated: 2022/03/07 17:26:25 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_same_picture_size(images_game *game_images, int width, int height,
		t_vars *vars)
{
	if (game_images->widht != width || game_images->height != height)
	{
		write(2, "Game Images do not have the same size!\n", 39);
		free_and_exit(vars);
	}
}

void	get_images(images_game *game_images, void *mlx, t_vars *vars)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	game_images->player = mlx_xpm_file_to_image(mlx, "images/Player.xpm",
			&width, &height);
	game_images->widht = width;
	game_images->height = height;
	game_images->coll = mlx_xpm_file_to_image(mlx, "images/coll.xpm", &width,
			&height);
	check_same_picture_size(game_images, width, height, vars);
	game_images->wall = mlx_xpm_file_to_image(mlx, "images/Tree.xpm", &width,
			&height);
	check_same_picture_size(game_images, width, height, vars);
	game_images->exit = mlx_xpm_file_to_image(mlx, "images/Exit.xpm", &width,
			&height);
	check_same_picture_size(game_images, width, height, vars);
	game_images->free = mlx_xpm_file_to_image(mlx, "images/Free.xpm", &width,
			&height);
	check_same_picture_size(game_images, width, height, vars);
}

void	sl_put_image(t_vars *vars, int x, int y, char c)
{
	if (c == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->game_images.player,
			x * vars->game_images.widht, y * vars->game_images.height);
	if (c == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->game_images.free, x
			* vars->game_images.widht, y * vars->game_images.height);
	if (c == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->game_images.coll, x
			* vars->game_images.widht, y * vars->game_images.height);
	if (c == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->game_images.exit, x
			* vars->game_images.widht, y * vars->game_images.height);
	if (c == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->game_images.wall, x
			* vars->game_images.widht, y * vars->game_images.height);
}

int	render_map(t_vars *vars)
{
	int		x;
	int		y;
	char	*moves;

	y = 0;
	while (y < vars->map_data.rows)
	{
		x = 0;
		while (x < vars->map_data.columns)
		{
			sl_put_image(vars, x, y, vars->map_data.map[y][x]);
			x++;
		}
		y++;
	}
	moves = ft_itoa(vars->map_data.moves);
	mlx_string_put(vars->mlx, vars->win, 0, 0, 0, moves);
	free(moves);
	return (0);
}
