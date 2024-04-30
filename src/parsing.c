/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:24:47 by mzhukova          #+#    #+#             */
/*   Updated: 2024/04/30 17:31:42 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_init(t_args *args)
{
	t_map	*map;

	args->line_count = 0;
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		so_short_error("Malloc failed!", args, false);
	map->line = get_next_line(args->fd);
	if (!map->line)
		so_short_error("Empty map!", args, true);
	args->line_count++;
	map->next = NULL;
	while (insert_end(&map, args) != 0)
		args->line_count++;
	copy_map(args, map);
	return (1);
}

int	map_validation(char *argv, t_args *args)
{
	char	*res;

	res = &argv[ft_strlen(argv) - 4];
	if (ft_strncmp(res, ".ber", 4) != 0)
		so_short_error("Incorrect map format!", args, true);
	check_walls(args);
	find_player(args);
	find_exit(args);
	find_collectibles(args);
	is_rectangular(args);
	if (is_solvable(args))
		free_split(args->map_copy);
	if (args->line_len > 76 || args->line_count > 43)
		so_short_error("Map is too big.", args, true);
	return (1);
}

int	check_walls(t_args *args)
{
	int	i;

	i = 0;
	while (args->map[0][i] != '\n')
	{
		if (args->map[0][i] != '1')
			so_short_error("Incorrect wall", args, true);
		i++;
	}
	i = 0;
	while (args->map[args->line_count - 1][i])
	{
		if (args->map[args->line_count - 1][i] != '1')
			so_short_error("Incorrect wall", args, true);
		i++;
	}
	i = 0;
	while (i < args->line_count)
	{
		if (args->map[i][0] != '1' ||
			args->map[i][ft_strlen(args->map[i]) - 2] != '1')
			so_short_error("Incorrect wall", args, true);
		i++;
	}
	return (1);
}

int	is_rectangular(t_args *args)
{
	int		i;

	i = 0;
	while (i < args->line_count - 1)
	{
		if ((int)ft_strlen(args->map[i]) != args->line_len)
			so_short_error("Map is not a rectangle!", args, true);
		i++;
	}
	if (((int)ft_strlen(args->map[i]) + 1) != args->line_len)
		so_short_error("Map is not a rectangle!", args, true);
	return (1);
}

int	is_solvable(t_args *args)
{
	int	i;

	i = 0;
	my_ff(args, args->player_x, args->player_y);
	while (i < args->line_count)
	{
		if (ft_strchr(args->map_copy[i], 'C')
			|| ft_strchr(args->map_copy[i], 'E'))
		{
			free_split(args->map_copy);
			so_short_error("Map cannot be solved.", args, true);
		}
		i++;
	}
	return (1);
}
