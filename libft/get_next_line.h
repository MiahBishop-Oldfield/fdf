/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:32:57 by mbishop-          #+#    #+#             */
/*   Updated: 2022/02/07 11:12:39 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// For *malloc(), free(), & read()*.

# include <stdlib.h>
# include <unistd.h>
# include "../includes/fdf.h"
# include "libft.h"

# define BUFFER_SIZE 32

size_t	ft_strlen(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif