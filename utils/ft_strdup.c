/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:09:29 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/17 12:09:33 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../pipex.h"

char	*ft_strdup( const char *src)
{
	int		i;
	int		len;
	char	*dst;

	len = ft_strlen (src);
	dst = malloc ((len + 1) * sizeof (char));
	if (dst == NULL)
	{
		free (dst);
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[len] = '\0';
	return (dst);
}
