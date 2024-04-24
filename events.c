/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:09:48 by mzhukova          #+#    #+#             */
/*   Updated: 2024/04/24 12:53:19 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_press(int keycode, t_env *env)
{
    // ESC key to exit
    if (keycode == 53)
	{
        mlx_destroy_window(env->mlx, env->mlx_win);
		exit(1);
	}
	// move right
	if (keycode == 124 || keycode == 2)
	{
        if (env->args->map[env->args->player_y][env->args->player_x + 1] != '1' && (env->args->map[env->args->player_y][env->args->player_x + 1]) && env->args->map[env->args->player_y][env->args->player_x + 1] != '\n')
		{
			env->args->player_x++;
			check_collects(env);
/* 			env->img->player_forward = true; */
			env->img->player_back = false;
			render_everything(env->img, env->mlx, env->mlx_win, env->args);
			env->args->moves++;
			printf("Moves: %i\n", env->args->moves);
		}
			
	}
	//move left
	if (keycode == 123 || keycode == 0)
	{
        if (env->args->map[env->args->player_y][env->args->player_x - 1] != '1' && env->args->map[env->args->player_y][env->args->player_x - 1])
		{
			env->args->player_x--;
			check_collects(env);
			env->img->player_back = true;
			render_everything(env->img, env->mlx, env->mlx_win, env->args);
			env->args->moves++;
			printf("Moves: %i\n", env->args->moves);
		}
	}
	//move_up
	if (keycode == 126 || keycode == 13)
	{
        if (env->args->map[env->args->player_y - 1][env->args->player_x] != '1' && env->args->map[env->args->player_y - 1][env->args->player_x])
		{
			env->args->player_y--;
			check_collects(env);
			render_everything(env->img, env->mlx, env->mlx_win, env->args);
			env->args->moves++;
			printf("Moves: %i\n", env->args->moves);
		}
	}
	//move_down
	if (keycode == 125 || keycode == 1)
	{
        if (env->args->map[env->args->player_y + 1][env->args->player_x] != '1' && env->args->map[env->args->player_y + 1][env->args->player_x])
		{
			env->args->player_y++;
			check_collects(env);
			render_everything(env->img, env->mlx, env->mlx_win, env->args);
			env->args->moves++;
			printf("Moves: %i\n", env->args->moves);
		}
	}
    return (0);
}

void check_collects(t_env *env)
{
	if (env->args->map[env->args->player_y][env->args->player_x] == 'C')
	{
		env->args->map[env->args->player_y][env->args->player_x] = '0';
		env->args->collects_amount--;
	}
	if (env->args->collects_amount <= 0)
		env->args->collects_collected = true;
}