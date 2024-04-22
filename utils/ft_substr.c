/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:37:24 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/16 11:37:26 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	lens;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start >= lens || len == 0)
		return (ft_strdup(""));
	if (len > (lens - start))
		len = lens - start;
	str = malloc((len + 1) * sizeof (char));
	if (str == NULL)
	{
		free (str);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[len] = '\0';
	return (str);
}
