/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:49:55 by derjavec          #+#    #+#             */
/*   Updated: 2024/02/15 17:05:02 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pipex.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	if (length == 0)
		return (0);
	while (first[i] && second[i] && i < (length - 1) && first[i] == second[i])
		i++;
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}
