/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:45:58 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/04/22 15:35:56 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int frameupdate(t_args *args, t_data *img, void *mlx, void *mlx_win)
{
    args->frame++;
    if(args->frame >= 50)
    {
        if (img->is_player_2)
        {
            img->player_pic_path = "./img/player/player_1.xpm";
            img->is_player_2 = false;
    		printf("check1\n");
        }
        else
        {
            img->player_pic_path = "./img/player/player_2.xpm";
            img->is_player_2 = true;
			printf("check2\n");
        }
        render_player(img, mlx, mlx_win, args, img->player_pic_path);
        args->frame = 0;
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
	args->fd = open(argv[1], O_RDONLY, 0644);
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
	render_walls(img, mlx, mlx_win, args);
	render_background(img, mlx, mlx_win, args);
	render_collects(img, mlx, mlx_win, args);
	render_exit(img, mlx, mlx_win, args);

	args->frame = 0;
	img->player_pic_path = "./img/player/player_1.xpm";
	img->is_player_2 = false;
	mlx_loop_hook(mlx, frameupdate, args);
	mlx_loop(mlx);
	return(0);
}