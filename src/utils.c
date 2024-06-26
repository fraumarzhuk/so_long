/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:56:39 by mzhukova          #+#    #+#             */
/*   Updated: 2024/04/30 18:13:06 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_ff(t_args *args, int x, int y)
{
	if (x > args->line_len || y > args->line_count)
		return ;
	if (args->map_copy[y][x] == '\n' || args->map_copy[y][x] == '\0')
		return ;
	if (args->map_copy[y][x] == '1' || args->map_copy[y][x] == 'X')
		return ;
	args->map_copy[y][x] = 'X';
	my_ff(args, x + 1, y);
	my_ff(args, x, y + 1);
	my_ff(args, x - 1, y);
	my_ff(args, x, y - 1);
	return ;
}

int	insert_end(t_map **map, t_args *args)
{
	t_map	*new_node;
	t_map	*curr;

	curr = *map;
	new_node = ft_calloc(sizeof(t_map), 1);
	if (!new_node)
		so_short_error("Malloc failed!", args, false);
	new_node->next = NULL;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
	new_node->line = get_next_line(args->fd);
	if (!new_node->line)
		return (0);
	return (1);
}

void	copy_map(t_args *args, t_map *map)
{
	int	i;

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
}

int	check_random_chars(t_args *args)
{
	args->x = 0;
	args->y = 0;
	while (args->y < args->line_count)
	{
		while (args->map[args->y][args->x] != '\n'
			&& args->map[args->y][args->x])
		{
			if (args->map[args->y][args->x] != '0'
				&& args->map[args->y][args->x] != '1'
				&& args->map[args->y][args->x] != 'C'
				&& args->map[args->y][args->x] != 'P'
				&& args->map[args->y][args->x] != 'E')
			{
				so_short_error("Incorrect map!", args, true);
			}
			args->x++;
		}
		args->x = 0;
		args->y++;
	}
	return (1);
}
