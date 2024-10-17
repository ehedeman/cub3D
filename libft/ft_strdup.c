/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:00:59 by ehedeman          #+#    #+#             */
/*   Updated: 2024/10/17 16:05:27 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_slen(char *str)
{
	int	a;

	a = 0;
	while (*str)
	{
		a++;
		str++;
	}
	return (a);
}

char	*ft_strdup(const char *s1)
{
	int		a;
	char	*b;
	char	*orig_b;
	char	*s1_cpy;

	s1_cpy = (char *)s1;
	a = ft_slen(s1_cpy);
	b = (char *) malloc(a + 1);
	if (!b)
	{
		return (0);
	}
	orig_b = b;
	while (*s1_cpy)
	{
		*b = *s1_cpy;
		b++;
		s1_cpy++;
	}
	*b = *s1_cpy;
	return (orig_b);
}

char *ft_strndup(const char *s, size_t n)
{
    char *dup;
    size_t i;

    dup = (char *)malloc(n + 1);
    if (!dup)
        return (NULL);
    i = 0;
    while (i < n && s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

//int	main(int argc, char **argv)
//{
//	char	*a;
//	int		i;
//	a = argv[1];
//	i = argc;
//	a = ft_strdup(a);
//	printf("%s\n", a);
//free(a);
//	a = strdup(a);
//	printf("%s", a);
//free(a);
//	return (0);
//}
