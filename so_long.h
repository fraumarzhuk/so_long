/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:45:27 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/05/04 16:50:56 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./libft/printf/ft_printf.h"
# include "./gnl/get_next_line_bonus.h"

// map for parsing the map
typedef struct map
{
	char		*line;
	struct map	*next;
}	t_map;

//linked list with collectibles
typedef struct collects
{
	int				x;
	int				y;
	struct collects	*next;
}	t_collects;

//the window scene(maybe rename it)
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
	int		color;
	char	*player_pic_path;
/* 	bool player_forward; */
	bool	player_back;
	bool	is_player_2;
	bool	player_exit;
}				t_data;

// game itself, important info about 
typedef struct args
{
	int			x;
	int			y;
	int			frame;	
	int			line_len;
	int			line_count;
	int			fd;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	char		**map;
	char		**map_copy;
	bool		found;
	bool		collects_found;
	bool		collects_collected;
	int			collects_amount;
	int			moves;
	t_collects	*collects;
}	t_args;

typedef struct s_env
{
	t_args	*args;
	t_data	*img;
	void	*mlx;
	void	*mlx_win;
}	t_env;

//Parsing
int		map_init(t_args *args);
int		map_validation(char *argv, t_args *args);
int		check_walls(t_args *args);
int		is_solvable(t_args *args);
int		is_rectangular(t_args *args);

//Locate
int		find_player(t_args *args);
int		find_exit(t_args *args);
int		find_collectibles(t_args *args);
void	collectibles_loop(t_args *args, t_collects *curr);

//Rendering
void	render_walls(t_data *img, void	*mlx, void *mlx_win, t_args *args);
void	render_background(t_data *img, void	*mlx, void *mlx_win, t_args *args);
void	render_collects(t_data *img, void	*mlx, void *mlx_win, t_args *args);
void	render_exit(t_data *img, void	*mlx, void *mlx_win, t_args *args);
void	render_everything(t_data *img, void	*mlx, void *mlx_win, t_args *args);

//Render player
void	render_player(t_data *img, void	*mlx, void *mlx_win, t_args *args);
void	player_forward(t_env *env);
void	player_back(t_env *env);
void	check_on_exit(t_env *env);
int		frameupdate(t_env *env);

//Utils
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_ff(t_args *args, int x, int y);
int		insert_end(t_map **map, t_args *args);
void	copy_map(t_args *args, t_map *map);
int		check_random_chars(t_args *args);
//Errors
void	so_short_error(char *str, t_args *args, bool collected);
//Events
int		key_press(int keycode, t_env *env);
void	check_collects(t_env *env);
void	move_on_y(t_env *env, int y, int x, int sign);
void	move_on_x(t_env *env, int y, int x, int sign);
#endif