/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvelayut <vvelayut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:35:46 by vvelayut          #+#    #+#             */
/*   Updated: 2022/06/06 15:35:51 by vvelayut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/* AIO function */
char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	char	*str;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
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

/* AIO function*/
char	*ft_strdup(char const *s1)
{
	char	*str;

	str = malloc(sizeof(*str) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	*str = '\0';
	return (str);
}
