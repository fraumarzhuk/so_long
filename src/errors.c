/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:55:35 by mzhukova          #+#    #+#             */
/*   Updated: 2024/05/04 17:13:23 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	so_short_error(char *str, t_args *args, bool collected)
{
	if (collected)
		free_split(args->map);
	ft_free(args);
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
