/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:12:24 by ehedeman          #+#    #+#             */
/*   Updated: 2024/10/11 14:09:03 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (dstsize > i && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize <= len)
		dst[dstsize - 1] = '\0';
	else
		dst[i] = '\0';
	return (len);
}

void	ft_strcpy(char *d, char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
}

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

// int main()
// {
//     char a[4];
//     char    b[5];
//     a[0] = 'a';
//     a[1] = 'a';
//     a[2] = 'a';
//     a[3] = '\0';
//     ft_strlcpy(b, a, 3);
// 	printf("%s", b);
//     return (0);
// }