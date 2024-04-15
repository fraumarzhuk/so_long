/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:24:47 by mzhukova          #+#    #+#             */
/*   Updated: 2024/04/15 12:58:56 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int insert_end(t_map **map, t_args *args)
{
	t_map *new_node;
	t_map *curr;
	
	curr = *map;
	new_node = ft_calloc(sizeof(t_map), 1);
	if (!new_node)
		so_short_error("Malloc failed!");
	new_node->next = NULL;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
	new_node->line = get_next_line(args->fd);
	if (!new_node->line)
		return (0);
	return(1);
}

int map_init(t_args *args)
{ 
	t_map	*map;
	int		i;

	args->line_count = 0;
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		so_short_error("Malloc failed!");
	map->line = get_next_line(args->fd);
	if (!map->line)
		so_short_error("Empty map!");
	args->line_count++;
	map->next = NULL;
	while (insert_end(&map, args) != 0)
		args->line_count++;
	i = 0;
	args->map = ft_calloc(args->line_count + 1, sizeof(char *));
	if (!args->map)
		so_short_error("Malloc failed.");
	while (i < args->line_count && map)
	{
		args->map[i] = ft_strdup(map->line);
		map = map->next;
		i++;
	}
	args->map[i] = NULL;
	return (1);
}

int map_validation(char *argv, t_args *args)
{
	char *res;

	res = &argv[ft_strlen(argv) - 4];
	if (ft_strncmp(res, ".ber", 4) != 0)
		so_short_error("Incorrect map format!");
	check_walls(args);
	return (1);
}

int check_walls(t_args *args)
{
	int i;
	i = 0;
	while (args->map[0][i] != '\n')
	{
		if (args->map[0][i] != '1')
			so_short_error("Incorrect wall");
		i++;
	}
	i = 0;
	while (args->map[args->line_count - 1][i])
	{
		if (args->map[args->line_count - 1][i] != '1')
			so_short_error("Incorrect wall");
		i++;
	}
	return (1);	
	 //check first and last character
	 //check last line
	 
}
