/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:45:58 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/05/04 17:17:59 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_args(t_args *args, char **argv, int argc)
{
	if (argc != 2)
		so_short_error("Incorrect amount of arguments.", args, false);
	args->fd = open(argv[1], O_RDONLY);
	if (args->fd < 0 || read(args->fd, 0, 0) < 0)
		so_short_error("Error reading a file.", args, false);
	if (!map_init(args))
		so_short_error("Error initing a map.", args, true);
	map_validation(argv[1], args);
}

void	init_img(t_data *img)
{
	img->height = 1080;
	img->width = 1920;
	img->player_pic_path = "./img/player/player_1.xpm";
	img->is_player_2 = false;
	img->player_back = false;
}

void	init_args(t_args *args)
{
	args->line_len = ft_strlen(&args->map[0][0]) - 1;
	args->collects_collected = false;
	args->moves = 0;
	args->frame = 0;
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_args	*args;
	t_data	*img;
	t_env	env;
	t_allocs *lst = ft_calloc(1, sizeof(t_allocs));

	if (lst == NULL)
		return (1);
	ft_allocs(lst);
	args = ft_malloc(sizeof(t_args));
	if (!args)
		so_short_error("Malloc failed!", args, false);
	check_args(args, argv, argc);
	init_args(args);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, args->line_len * 65,
			args->line_count * 65, "So long!");
	img = ft_malloc(sizeof(t_data));
	if (!img)
		so_short_error("Malloc failed!", args, true);
	init_img(img);
	render_everything(img, mlx, mlx_win, args);
	env = (t_env){args, img, mlx, mlx_win};
	mlx_loop_hook(mlx, frameupdate, &env);
	mlx_key_hook(mlx_win, key_press, &env);
	mlx_loop(mlx);
	return (0);
}
