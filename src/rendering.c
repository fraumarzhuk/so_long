/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:35:09 by mzhukova          #+#    #+#             */
/*   Updated: 2024/05/04 17:15:12 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_walls(t_data *img, void	*mlx, void *mlx_win, t_args *args)
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		x;
	int		y;

	img_width = 65;
	img_height = 65;
	x = 0;
	y = 0;
	relative_path = "./img/stones.xpm";
	img->img = mlx_xpm_file_to_image(mlx, relative_path,
			&img_width, &img_height);
	while (y < args->line_count)
	{
		while (args->map[y][x] != '\n' && args->map[y][x])
		{
			if (args->map[y][x] == '1')
				mlx_put_image_to_window(mlx, mlx_win, img->img, x * 65, y * 65);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_destroy_image(mlx, img->img);
}

void	render_background(t_data *img, void	*mlx, void *mlx_win, t_args *args)
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		x;
	int		y;

	img_width = 65;
	img_height = 65;
	x = 0;
	y = 0;
	relative_path = "./img/bg.xpm";
	img->img = mlx_xpm_file_to_image(mlx, relative_path,
			&img_width, &img_height);
	while (y < args->line_count)
	{
		while (args->map[y][x] != '\n' && args->map[y][x])
		{
			if (args->map[y][x] == '0' || args->map[y][x] == 'C' ||
				args->map[y][x] == 'P' || args->map[y][x] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, img->img, x * 65, y * 65);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_destroy_image(mlx, img->img);
}

void	render_collects(t_data *img, void	*mlx, void *mlx_win, t_args *args)
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		x;
	int		y;

	img_width = 65;
	img_height = 65;
	x = 0;
	y = 0;
	relative_path = "./img/coin.xpm";
	img->img = mlx_xpm_file_to_image(mlx, relative_path,
			&img_width, &img_height);
	while (y < args->line_count)
	{
		while (args->map[y][x] != '\n' && args->map[y][x])
		{
			if (args->map[y][x] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, img->img, x * 65, y * 65);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_destroy_image(mlx, img->img);
}

void	render_exit(t_data *img, void	*mlx, void *mlx_win, t_args *args)
{
	char	*img_path;
	int		img_width;
	int		img_height;
	int		x;
	int		y;

	img_width = 65;
	img_height = 65;
	x = 0;
	y = 0;
	img_path = "./img/door_closed.xpm";
	if (args->collects_collected == true)
		img_path = "./img/door_open.xpm";
	img->img = mlx_xpm_file_to_image(mlx, img_path, &img_width, &img_height);
	while (y < args->line_count)
	{
		while (args->map[y][x] != '\n' && args->map[y][x])
		{
			if (args->map[y][x] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, img->img, x * 65, y * 65);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_destroy_image(mlx, img->img);
}

void	render_everything(t_data *img, void	*mlx, void *mlx_win, t_args *args)
{
	render_walls(img, mlx, mlx_win, args);
	render_background(img, mlx, mlx_win, args);
	render_collects(img, mlx, mlx_win, args);
	render_exit(img, mlx, mlx_win, args);
}
