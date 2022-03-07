#ifndef SO_LONG_H

#define SO_LONG_H

#include "Libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "mlx/mlx.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct 
{
	int 	columns;
	int		rows;
	char	**map;
	int		player_pos[2];
	int		colls;
	int		moves;
}	data_map;

typedef struct 
{
	void	*player;
	void	*coll;
	void	*exit;
	void	*free;
	void	*wall;
	int		widht;
	int		height;
}	images_game;

typedef struct so_long_game
{
	void		*mlx;
	void		*win;
	data_map	map_data;
	images_game	game_images;
}				t_vars;



void		no_surrounding_wall(char a);
void		non_rectangular_map(void);
void		check_interior(char a);
void		check_rectangular_shape(char **map, int rows, int columns);
void		check_amount_of_extra_fields(int *different_tiles);
void		check_all_necessities(char **map, int rows, int columns);
void		check_validity(char **map, int rows, int columns);
void		check_arg_number(int argc);
int is_ber_file(char *map);
void		check_file(char *file);
char		**check_input(int argc, char **argv, data_map *map_data);
int			open_fd(char *file);
int			get_columns(char *file);
int			get_rows(char *file);
char		**create_map(char *file, int rows, int columns);
int	move_up(t_vars *vars);
int	move_left(t_vars *vars);
int	move_down(t_vars *vars);
int	move_right(t_vars *vars);
int	close_game(t_vars *vars);
void	game_function(t_vars vars);





void	check_same_picture_size(images_game *game_images, int width, int height,
		t_vars *vars);
void	get_images(images_game *game_images, void *mlx, t_vars *vars);
void	sl_put_image(t_vars *vars, int x, int y, char c);

int	render_map(t_vars *vars);
void	free_and_exit(t_vars *vars);


#endif