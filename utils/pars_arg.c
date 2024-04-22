/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:56:03 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/17 13:56:05 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../pipex.h"

char	**pars_arg(char *str, char **split_paths, int argc, t_bonus *cmd)
{
	char	**split_args;
	char	special_c[3];
	int		len;

	len = ft_strlen(str);
	if (len >= 3 && str[len - 3] == '.' && str[len - 2] == 's'
		&& str[len - 1] == 'h')
	{
		str = ft_strjoin("sh ", str);
		len = -1;
	}
	special_c[0] = '\'';
	special_c[1] = '\"';
	special_c[2] = '\0';
	split_args = ft_split(str, ' ', special_c);
	if (split_args == NULL)
	{
		if (len == -1)
			free (str);
		error_bonus("Argument spliting error", cmd, split_paths, argc);
	}
	if (len == -1)
		free (str);
	return (split_args);
}
