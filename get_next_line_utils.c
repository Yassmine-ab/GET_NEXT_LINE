#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (--size && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (src_len);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s) + 1;
	str = malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, size);
	return (str);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size < dst_len)
		return (size + src_len);
	if (size > dst_len)
	{
		dst += dst_len;
		while (--size > dst_len && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (dst_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(str + s1_len, s2, s2_len + 1);
	return (str);
}
