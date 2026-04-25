#include "get_next_line.h"

static bool	append_buffer(char **remainder, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(*remainder, buffer);
	free(*remainder);
	*remainder = tmp;
	if (!tmp)
		return (false);
	return (true);
}

static char	*extract_line(char **remainder)
{
	char	*line;
	char	*tmp;
	size_t	len;

	len = 0;
	while ((*remainder)[len] && (*remainder)[len] != '\n')
		len++;
	if ((*remainder)[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *remainder, len + 1);
	tmp = ft_strdup((*remainder) + len);
	free(*remainder);
	*remainder = tmp;
	if (!*remainder || !**remainder)
		(free(*remainder), *remainder = NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!remainder)
		remainder = ft_strdup("");
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!remainder || !buffer)
		return (free(buffer), free(remainder), remainder = NULL, NULL);
	bytes_read = 1;
	while (!ft_strchr(remainder, '\n') && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(remainder), remainder = NULL, NULL);
		buffer[bytes_read] = '\0';
		if (append_buffer(&remainder, buffer) == false)
			return (free(buffer), NULL);
	}
	free(buffer);
	if (!remainder || !*remainder)
		return (free(remainder), remainder = NULL, NULL);
	return (extract_line(&remainder));
}
