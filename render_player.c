/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:58:46 by mzhukova          #+#    #+#             */
/*   Updated: 2024/04/30 14:05:51 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	render_player(t_data *img, void	*mlx, void *mlx_win, t_args *args, char	*player_path)
{
	int		img_width;
	int		img_height;

	img_width = 65;
	img_height = 33;
	img->img = mlx_xpm_file_to_image(mlx, player_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img->img, args->player_x * 65,
		args->player_y * 65);
}

void	player_forward(t_env *env)
{
	if (env->img->is_player_2)
	{
		env->img->player_pic_path = "./img/player/player_1.xpm";
		env->img->is_player_2 = false;
	}
	else
	{
		env->img->player_pic_path = "./img/player/player_2.xpm";
		env->img->is_player_2 = true;
	}
}

void	player_back(t_env *env)
{
	if (env->img->is_player_2)
	{
		env->img->player_pic_path = "./img/player/player_3.xpm";
		env->img->is_player_2 = false;
	}
	else
	{
		env->img->player_pic_path = "./img/player/player_4.xpm";
		env->img->is_player_2 = true;
	}
}

void	check_on_exit(t_env *env)
{
	if ((env->args->player_x == env->args->exit_x)
		&& (env->args->player_y == env->args->exit_y))
	{
		if (env->args->collects_collected == true)
		{
			render_player(env->img, env->mlx, env->mlx_win, env->args,
				"./img/player/player_exit.xpm");
			mlx_destroy_window(env->mlx, env->mlx_win);
			exit(0);
		}
		env->img->player_pic_path = "./img/player/player_exit.xpm";
		env->img->player_exit = true;
	}
	else
		env->img->player_exit = false;
}

int	frameupdate(t_env *env)
{
	env->args->frame++;
	if (env->args->frame >= 2000)
	{
		check_on_exit(env);
		if (env->img->player_back == true && env->img->player_exit == false)
			player_back(env);
		else if (env->img->player_back == false
			&& env->img->player_exit == false)
			player_forward(env);
		render_player(env->img, env->mlx, env->mlx_win, env->args, env->img->player_pic_path);
		env->args->frame = 0;
	}
	return (0);
}
