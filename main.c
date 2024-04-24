/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:45:58 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/04/24 12:58:42 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void player_forward(t_env *env)
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
void player_back(t_env *env)
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

int frameupdate(t_env *env)
{
    env->args->frame++;
    if(env->args->frame >= 2000)
    {
		if (env->img->player_back == true)
			player_back(env);
		else
			player_forward(env);
        render_player(env->img, env->mlx, env->mlx_win, env->args, env->img->player_pic_path);
        env->args->frame = 0;
    }
    return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_args	*args;
	t_data	*img;
	
	args = malloc(sizeof(t_args));
	if (!args)
    	so_short_error("Malloc failed!");
	if (argc != 2)
		so_short_error("Incorrect amount of arguments.");
	args->fd = open(argv[1], O_RDONLY);
	if (args->fd < 0 || read(args->fd, 0, 0) < 0)
		so_short_error("Error reading a file.");
	if (!map_init(args))
		so_short_error("Error initing a map.");
	map_validation(argv[1], args);
	mlx = mlx_init();
	args->line_len = ft_strlen(&args->map[0][0]) - 1;
	mlx_win = mlx_new_window(mlx, args->line_len * 65, args->line_count * 65, "So long!");
	img = malloc(sizeof(t_data));
	if (!img)
		so_short_error("Malloc failed!");
	img->height = 1080;
	img->width = 1920;
	render_everything(img, mlx, mlx_win, args);
	args->moves = 0;
	args->frame = 0;
	img->player_pic_path = "./img/player/player_1.xpm";
	img->is_player_2 = false;
	t_env env = {args, img, mlx, mlx_win};
	mlx_loop_hook(mlx, frameupdate, &env);
	mlx_key_hook(mlx_win, key_press, &env);
	mlx_loop(mlx);
	return(0);
}