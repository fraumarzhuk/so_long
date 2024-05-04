/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_undecim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:03:43 by mzhukova          #+#    #+#             */
/*   Updated: 2024/05/04 17:08:19 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_s(char *str, unsigned int n, unsigned int len)
{
	unsigned int	i;

	i = len - 1;
	if (n == 0)
	{
		str[0] = '0';
	}
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
}

char	*convert_num(unsigned int n)
{
	char				*res;
	unsigned int		len;
	unsigned int		temp_n;

	len = 0;
	temp_n = n;
	if (n <= 0)
		len++;
	while (temp_n != 0 && temp_n != 'u')
	{
		len++;
		temp_n /= 10;
	}
	res = ft_malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	fill_s(res, n, len);
	return (res);
}

int	to_undecim(int c)
{
	char	*res;
	int		len;

	res = convert_num(c);
	if (res)
	{
		write(1, res, ft_strlen(res));
		len = ft_strlen(res);
		free(res);
		return (len);
	}
	free(res);
	return (1);
}
