/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:24:47 by mzhukova          #+#    #+#             */
/*   Updated: 2024/04/30 13:46:37 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int map_init(t_args *args)
{ 
	t_map	*map;
	int		i;

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
	i = 0;
	args->map = ft_calloc(args->line_count + 1, sizeof(char *));
	args->map_copy = ft_calloc(args->line_count + 1, sizeof(char *));
	if (!args->map)
		so_short_error("Malloc failed.", args, true);
	while (i < args->line_count && map)
	{
		args->map[i] = ft_strdup(map->line);
		args->map_copy[i] = ft_strdup(map->line);
		map = map->next;
		i++;
	}
	args->map[i] = NULL;
	args->map_copy[i] = NULL;
	args->line_len = (int)ft_strlen(args->map[0]);
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

int find_player(t_args *args)
{
	int		x;
	int		y;
	bool	found;

	x = 0;
	y = 0;
	found = false;	
	while (y < args->line_count)
	{
		while (args->map[y][x] != '\n' && args->map[y][x])
		{
			if (args->map[y][x] == 'P')
			{
				if (args->map[y][x] == 'P' && found)
					so_short_error("Too many players!", args, true);
				args->player_x = x;
				args->player_y = y;
				found = true;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (!found)
		return (0);
	return (1);
}

int	find_exit(t_args *args)
{
	int		x;
	int		y;
	bool	found;

	x = 0;
	y = 0;
	found = false;
	while (y < args->line_count)
	{
		while (args->map[y][x] != '\n' && args->map[y][x])
		{
			if (args->map[y][x] == 'E')
			{
				if (args->map[y][x] == 'E' && found)
					so_short_error("Two many exits!", args, true);
				args->exit_x = x;
				args->exit_y = y;
				found = true;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (!found)
		return (0);
	return (1);
}
int is_rectangular(t_args *args)
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

int	find_collectibles(t_args *args)
{
	int			x;
	int			y;
	t_collects	*curr;

	x = 0;
	y = 0;
	curr = args->collects;
	args->collects_found = false;
	args->collects_amount = 0;
	curr = malloc(sizeof(t_collects));
	while (y < args->line_count)
	{
		while (args->map[y][x] != '\n' && args->map[y][x])
		{
			if (args->map[y][x] == 'C')
			{			
				if (args->map[y][x] == 'C' && args->collects_found)
				{
					curr = curr->next;
					curr = malloc(sizeof(t_collects));
					curr->next = NULL;
				}
				curr->x = x;
				curr->y = y;
				args->collects_found = true;
				args->collects_amount++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (!args->collects_found)
		so_short_error("No collectibles found.", args, true);
	return (1);
}

int is_solvable(t_args *args)
{
    my_ff(args, args->player_x, args->player_y);
	int i;
/* 	int i = 0;
 	while (i < args->line_count)
	{
		printf("%s", args->map_copy[i]);
		i++;
	}
	printf("\n"); */
	i = 0;
	while (i < args->line_count)
	{
		if (ft_strchr(args->map_copy[i], 'C') || ft_strchr(args->map_copy[i], 'E'))
		{
			free_split(args->map_copy);
			so_short_error("Map cannot be solved.", args, true);
		}	
		i++;
	}
    return(1);
}
