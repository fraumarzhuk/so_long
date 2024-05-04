/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:55:35 by mzhukova          #+#    #+#             */
/*   Updated: 2024/05/04 17:46:57 by mzhukova         ###   ########.fr       */
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

void	declare_magic_list(void)
{
	t_allocs	*lst;

	lst = ft_calloc(1, sizeof(t_allocs));
	if (lst == NULL)
		exit(1);
	ft_allocs(lst);
}
