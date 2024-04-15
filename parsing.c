/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:24:47 by mzhukova          #+#    #+#             */
/*   Updated: 2024/04/15 10:47:48 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int insert_end(t_map **map, t_args *args)
{
	t_map *new_node;
	t_map *curr;
	
	curr = *map;
	new_node = malloc(sizeof(t_map));
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
	map = malloc(sizeof(t_map));
	if (!map)
		so_short_error("Malloc failed!");
	map->next = NULL;
	while (insert_end(&map, args) != 0)
		args->line_count++;
	i = 0;
	args->map = malloc(sizeof(char *) * (args->line_count + 1));
	if (!args->map)
		so_short_error("Malloc failed.");
	while (i < args->line_count)
	{
		args->map[i] = map->line;
		map = map->next;
		i++;
	}
	args->map[i] = NULL;
	printf("Check map 0: %s\n", args->map[0]);
/* 	i = 0;
    while (args->map[i] != NULL) {
        printf("%s\n", args->map[i]);
        i++;
	} */
	return (1);
}