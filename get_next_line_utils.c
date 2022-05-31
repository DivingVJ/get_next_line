#include "get_next_line.h"

/* strlen - returns number of character in a string */
/* Cannot be protected, will cause compile error (test agaim) */
size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

/* strlen - returns number of character in a string before \n */
/* Cannot be protected, will cause compile error (test agaim) */
size_t	ft_linelen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\n' && str[count] != '\0')
		count++;
	return (count);
}

/* substr - returns pointer to substring from start, length of len */
/* Protected if str is NULL. Checks if start & len dont go beyond str */
char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*subptr;

	i = 0;
	if (str == NULL)
		return (NULL);
	size = ft_strlen(str);
	if (start > size)
		start = size;
	if (len > size - start)
		len = size - start;
	subptr = (char *)malloc(len + 1);
	if (subptr == NULL)
		return (NULL);
	while (i < len)
	{
		subptr[i] = str[start];
		i++;
		start++;
	}
	subptr[i] = '\0';
	return (subptr);
}

/* strcat - Cats size - 1 chars from src to dest with null added */
/* Size is full size of string to be created */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	offset;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	offset = destlen;
	if (size < destlen)
		return (size + srclen);
	while ((offset < size - 1) && (src[i] != '\0') && (size != 0))
	{
		dest[offset] = src[i];
		offset++;
		i++;
	}
	dest[offset] = '\0';
	return (destlen + srclen);
}

/* strjoin - returns ptr to new string after  cat 2 strings */
/* Protected - null *s1 & *s2 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sumlen;
	char	*joinptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	sumlen = ft_strlen(s1) + ft_strlen(s2);
	joinptr = malloc(sizeof(char) * (sumlen + 1));
	if (joinptr == NULL)
		return (NULL);
	*joinptr = '\0';
	ft_strlcat(joinptr, s1, ft_strlen(s1) + 1);
	ft_strlcat(joinptr, s2, sumlen + 1);
	return (joinptr);
}

/* strchr - returns pointer to the first occurence of c */
char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*ptr;

	i = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == (char)c)
		{
			ptr = (char *)&str[i];
			return (ptr);
		}
		i++;
	}
	return (NULL);
}
