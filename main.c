/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:45:58 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/04/15 14:12:04 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
/* 	void	*mlx;
	void	*mlx_win; */
	t_args	*args;
	
	args = malloc(sizeof(t_args));
	if (!args)
    	so_short_error("Malloc failed!");
	if (argc != 2)
		so_short_error("Incorrect amount of arguments.");
	args->fd = open(argv[1], O_RDONLY, 0644);
	if (args->fd < 0 || read(args->fd, 0, 0) < 0)
		so_short_error("Error reading a file.");
	if (map_init(args))
		ft_printf("Success. num or args: %i\n", args->line_count);
	map_validation(argv[1], args);
/* 	mlx = mlx_init(); */
/* 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!"); 
	mlx_loop(mlx); */
	return(0);
}