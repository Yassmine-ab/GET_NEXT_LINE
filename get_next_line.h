#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* ================================ INCLUDES ================================ */

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

/* ================================ DEFINES ================================= */

# define BUFFER_SIZE 1000

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
