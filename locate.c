/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:54:06 by mzhukova          #+#    #+#             */
/*   Updated: 2024/05/02 21:58:31 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectibles_loop(t_args *args, t_collects *curr)
{
	while (args->map[args->y][args->x] != '\n'
			&& args->map[args->y][args->x])
	{
		if (args->map[args->y][args->x] == 'C')
		{
			if (args->map[args->y][args->x] == 'C' && args->collects_found)
			{
				curr = curr->next;
				curr = malloc(sizeof(t_collects));
				curr->next = NULL;
			}
			curr->x = args->x;
			curr->y = args->y;
			args->collects_found = true;
			args->collects_amount++;
		}
		args->x++;
	}
	args->x = 0;
	args->y++;
}

int	find_collectibles(t_args *args)
{
	t_collects	*curr;

	args->x = 0;
	args->y = 0;
	curr = args->collects;
	args->collects_found = false;
	args->collects_amount = 0;
	curr = malloc(sizeof(t_collects));
	while (args->y < args->line_count)
	{
		collectibles_loop(args, curr);
	}
	free(curr);
	if (!args->collects_found)
		so_short_error("No collectibles found.", args, true);
	return (1);
}

int	find_exit(t_args *args)
{
	args->x = 0;
	args->y = 0;
	args->found = false;
	while (args->y < args->line_count)
	{
		while (args->map[args->y][args->x] != '\n'
			&& args->map[args->y][args->x])
		{
			if (args->map[args->y][args->x] == 'E')
			{
				if (args->map[args->y][args->x] == 'E' && args->found)
					so_short_error("Two many exits!", args, true);
				args->exit_x = args->x;
				args->exit_y = args->y;
				args->found = true;
			}
			args->x++;
		}
		args->x = 0;
		args->y++;
	}
	if (!args->found)
		return (0);
	return (1);
}

int	find_player(t_args *args)
{
	args->x = 0;
	args->y = 0;
	args->found = false;
	while (args->y < args->line_count)
	{
		while (args->map[args->y][args->x] != '\n'
			&& args->map[args->y][args->x])
		{
			if (args->map[args->y][args->x] == 'P')
			{
				if (args->map[args->y][args->x] == 'P' && args->found)
					so_short_error("Too many players!", args, true);
				args->player_x = args->x;
				args->player_y = args->y;
				args->found = true;
			}
			args->x++;
		}
		args->x = 0;
		args->y++;
	}
	if (!args->found)
		return (0);
	return (1);
}
