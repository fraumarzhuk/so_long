/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:45:27 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/04/10 16:22:52 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

#define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
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
	char **map;
	
} t_args;

int		map_init(t_args *args);
int		insert_end(t_map **map, t_args *args);
void	so_short_error(char *str);

#endif