/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:05:15 by mzhukova          #+#    #+#             */
/*   Updated: 2024/05/04 17:10:43 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../leak_killer/ft_alloc.h"

# ifndef MAX_FD
#  define MAX_FD 10240
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ftt_strjoin(char const *s1, char const *s2);
char	*ftt_strrchr(const char *s, int c);
size_t	ftt_strlen(const char *s);
char	*ftt_strdup(const char *s1);
void    *ftt_calloc(int count, int size);

#endif