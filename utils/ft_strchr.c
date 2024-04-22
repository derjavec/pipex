/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:34:38 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/19 13:34:40 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../pipex.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;
	int	count;
	int	lenstr;

	i = 0;
	count = 0;
	lenstr = ft_strlen(str);
	while (i <= lenstr)
	{
		if (str[i] != (unsigned char) c)
			count++;
		else
			return ((char *)str + count);
		i++;
	}
	return (NULL);
}
