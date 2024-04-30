/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:54:06 by mzhukova          #+#    #+#             */
/*   Updated: 2024/04/30 13:55:18 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
