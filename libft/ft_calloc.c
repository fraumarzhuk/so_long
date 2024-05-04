/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:40:19 by mzhukova          #+#    #+#             */
/*   Updated: 2024/05/04 17:04:44 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len);

void	*ft_calloc(size_t count, size_t size)
{
	int	*p;

	p = ft_malloc(count * size);
	if (p != NULL)
		ft_memset(p, 0, count * size);
	return (p);
}