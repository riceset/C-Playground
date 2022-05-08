/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 07:11:00 by tkomeno           #+#    #+#             */
/*   Updated: 2022/05/08 18:23:05 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

char	*ft_strncpy(char *dst, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	return ((size_t)(p - s));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t cpysize)
{
	size_t	i;

	if (cpysize)
	{
		i = -1;
		while (src[++i] && i < cpysize - 1)
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t f_dst_s)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dst && f_dst_s == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (f_dst_s == 0)
		return (src_len);
	if (dst_len < f_dst_s)
	{
		i = -1;
		while (src[++i] && i + 1 < f_dst_s - dst_len)
			dst[dst_len + i] = src[i];
		dst[dst_len + i] = '\0';
		return (src_len + dst_len);
	}
	return (src_len + f_dst_s);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s1) + 1;
	dup = malloc(size);
	if (dup)
		ft_strlcpy(dup, s1, size);
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j;
	size_t	js;

	if (s1 && s2)
	{
		js = (ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char);
		j = malloc(js);
		if (j)
		{
			ft_strlcpy(j, s1, ft_strlen(s1) + 1);
			ft_strlcat(j, s2, js);
			return (j);
		}
	}
	return (NULL);
}

void	*ft_bzero(void *b, size_t len)
{
	size_t			i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = 0;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*b;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	b = malloc(count * size);
	if (b)
		ft_bzero(b, count * size);
	return (b);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dup;

	dup = malloc(n + 1);
	if (dup)
		ft_strlcpy(dup, s1, n + 1);
	return (dup);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (dst < src)
		while (++i < n)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	i = n + 1;
	if (dst > src)
		while (--i > 0)
			((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
	return (dst);
}
