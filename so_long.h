/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:45:27 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/04/15 15:20:01 by mzhukova         ###   ########.fr       */
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

typedef struct map
{
	char *line;
	struct map *next;
	
}	t_map;

typedef struct args
{
	int line_count;
	int fd;
	int player_x;
	int player_y;
	int exit_x;
	int exit_y;
	char **map;
	
} t_args;

int		map_init(t_args *args);
int		insert_end(t_map **map, t_args *args);
void	so_short_error(char *str);
int		map_validation(char *argv, t_args *args);
int		check_walls(t_args *args);
int		find_player(t_args *args);
int		find_exit(t_args *args);

#endif