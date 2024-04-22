/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:45:27 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/04/22 11:57:17 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

#define SO_LONG_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <mlx.h>
# include "./libft/libft.h"
# include "./libft/printf/ft_printf.h"
# include "./gnl/get_next_line_bonus.h"

// map for parsing the map
typedef struct map
{
	char *line;
	struct map *next;
	
}	t_map;

//linked list with collectibles
typedef struct collects
{
	int x;
	int y;
	struct collects *next;
}	t_collects;

//the window scene(maybe rename it)
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
	int		color;
}				t_data;

// game itself, important info about 
typedef struct args
{
	int line_count;
	int fd;
	int player_x;
	int player_y;
	int exit_x;
	int exit_y;
	char **map;
	bool collects_found;
	int collects_amount;
	t_collects *collects;
	
} t_args;

//Parsing
int		map_init(t_args *args);
int		insert_end(t_map **map, t_args *args);

void	so_short_error(char *str);
int		map_validation(char *argv, t_args *args);
int		check_walls(t_args *args);
int		find_player(t_args *args);
int		find_exit(t_args *args);
int		find_collectibles(t_args *args);

//Rendering
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	render_walls(t_data *img, void	*mlx, void *mlx_win, t_args *args);
void	render_background(t_data *img, void	*mlx, void *mlx_win, t_args *args);
void	render_collects(t_data *img, void	*mlx, void *mlx_win, t_args *args);
void	render_exit(t_data *img, void	*mlx, void *mlx_win, t_args *args);

#endif