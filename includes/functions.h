/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:32:37 by ehedeman          #+#    #+#             */
/*   Updated: 2024/10/11 15:01:41 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//for map parsing
int	ft_skip_til_map(t_game *game);
int	ft_is_map_char(char c);
int	ft_read_map(int fd, t_game *game);