/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:45:58 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/04/10 11:28:45 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_args	*args;
	
	args = malloc(sizeof(t_args));
	if (!args)
    return (ft_printf("Memory allocation failed!\n"));
	if (argc != 2)
		return(ft_printf("Incorrect amount of arguments!\n"));
	args->fd = open(argv[1], O_RDONLY, 0644);
	if (args->fd < 0 || read(args->fd, 0, 0) < 0)
		return(ft_printf("Error reading a file.\n"));
	if (map_validation(args))
		ft_printf("Success.\n");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}