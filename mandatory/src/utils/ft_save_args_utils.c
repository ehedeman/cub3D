/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ****.c		                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ****** <******@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:33:17 by ******           #+#    #+#              */
/*   Updated: 2024/10/11 13:09:41 by ******           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	ft_check_args(t_game *game)
{
	if (!game->args.north || !game->args.south || !game->args.east
		|| !game->args.west)
		return (true);
	return (false);
}

static size_t	get_param_len(const char *s, size_t n);

char	*get_param(const char *s, size_t n)
{
    char	*dup;
    size_t	i;
    size_t	j;
    size_t	len;

    len = get_param_len(s, n);
    dup = (char *)malloc(len + 1);
    if (!dup)
        return (NULL);
    i = 0;
    j = 0;
    while (i < n && s[i] != '\n')
    {
        if (s[i] != ' ')
        {
            dup[j] = s[i];
            j++;
        }
        i++;
    }
    dup[j] = '\0';
    return (dup);
}

static size_t	get_param_len(const char *s, size_t n)
{
    size_t	len;
    size_t	i;

    len = 0;
    i = 0;
    while (i < n && s[i] != '\n')
    {
        if (s[i] != ' ')
            len++;
        i++;
    }
    return (len);
}
