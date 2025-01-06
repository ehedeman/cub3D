/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:53:15 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/03 14:48:49 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) +1);
	ft_strlcat(str + ft_strlen(s1), s2, len);
	return (str);
}

//int main()
//{
//	char *a;
//
//	a = ft_strjoin("hello how ", "are you");
//	printf("%s\n", a);
//	free(a);
//	return (0);
//}

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		len;
	char	*str;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) +1);
	ft_strlcat(str + ft_strlen(s1), s2, len);
	free(s1);
	free(s2);
	return (str);
}
