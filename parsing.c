/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:24:47 by mzhukova          #+#    #+#             */
/*   Updated: 2024/04/10 19:41:33 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int insert_end(t_map **map, t_args *args)
{
	// t_map *new_node;
	t_map *curr;
	
	curr = *map;
	// new_node = malloc(sizeof(t_map));
	// if (!new_node)
	// 	so_short_error("Malloc failed!");
	// new_node->next = NULL;
	
	if (*map && (*map)->line)
	{
		while (curr->next)
			curr = curr->next;
		curr->next = malloc(sizeof(t_map));
		curr->next->line = get_next_line(args->fd);
		curr->next->next = NULL;
		if (curr && curr->next && !curr->next->line)
		{
			free(curr->next);
			curr->next = NULL;
			return (0);
		}
	}
	else
	{
		curr->line = get_next_line(args->fd);
		curr->next = NULL;
	}
	// printf("Check int: %i", new_node->check);
	// new_node->line = get_next_line(args->fd);
	// if (!new_node->line)
	// 	return (0);
	return(1);
}

int map_init(t_args *args)
{ 
	t_map	*map;
	// t_map	*temp;
	t_map	*print_test;
	int		i;

	args->line_count = 0;
	map = malloc(sizeof(t_map));
	if (!map)
		so_short_error("Malloc failed!");
	map->next = NULL;
	while (insert_end(&map, args) != 0)
		args->line_count++;
	i = 0;
	// args->map = malloc(sizeof(char *) * (args->line_count + 1));
	// if (!args->map)
	// 	so_short_error("Malloc failed.");


	// temp = map;
	// while (i < args->line_count)
	// {
	// 	// args->map[i] = temp->line;
		
	// 	args->map[i] = ft_strdup(temp->line);
	// 	temp = temp->next;
	// 	i++;
	// }

	print_test = map;
	int counter = 0;
	while (print_test)
	{
		counter++;
		if (print_test && print_test->line)
			printf("%zu\n", ft_strlen(print_test->line));
		printf("%d\n", counter);
		
		
		print_test = print_test->next;
	}


	// args->map[i] = NULL;
	// printf("Check\n");
	// i = 0;
	// printf("Check map 0: %s\n", args->map[0]);
/* 	i = 0;
    while (args->map[i] != NULL) {
        printf("%s\n", args->map[i]);
        i++;
	} */
	return (1);
}
