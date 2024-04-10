/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:24:47 by mzhukova          #+#    #+#             */
/*   Updated: 2024/04/10 12:58:44 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void insert_end(t_map *map)

int map_validation(t_args *args)
{
	t_map *map;

	map = NULL;
	while (true)
	{
		map->line = get_next_line(args->fd);
		args->line_count += 1;
		if (map->line == NULL)
			break ;
	}
}
