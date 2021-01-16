/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:37:35 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/04 17:26:38 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

char		*ft_strchr(const char *str, int ch)
{
	size_t	idx;
	char	*result;

	if (str == NULL)
		return (NULL);
	result = (char *)str;
	idx = 0;
	while (1)
	{
		if (str[idx] == (char)ch)
		{
			return (&result[idx]);
		}
		if (str[idx] == '\0')
		{
			return (NULL);
		}
		idx++;
	}
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int idx;

	if (dstsize == 0)
		return (ft_strlen(src));
	idx = 0;
	while (!(idx >= dstsize - 1 || src[idx] == '\0'))
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = '\0';
	return (ft_strlen(src));
}

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dstlen;
	size_t		srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= dstsize)
		return (dstsize + srclen);
	ft_strlcpy(&dst[dstlen], src, dstsize - dstlen);
	return (dstlen + srclen);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len_total;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_total = len_s1 + len_s2 + 1;
	ptr = (char *)malloc(len_total * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, len_s1 + 1);
	ft_strlcat(ptr, s2, len_total);
	return (ptr);
}
