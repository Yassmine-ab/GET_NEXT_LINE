/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassabda <yassabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:14:45 by yassabda          #+#    #+#             */
/*   Updated: 2026/04/26 00:05:21 by yassabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* ================================ INCLUDES ================================ */

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

/* ================================ DEFINES ================================= */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

/* ========================== FUNCTION PROTOTYPES =========================== */

/* --- Main function --- */

char	*get_next_line(int fd);

/* --- Helper Functions --- */

char	*ft_strchr(const char *string, int searchedChar);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
