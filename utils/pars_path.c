/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:56:19 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/17 13:56:22 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../pipex.h"

char	**pars_path(char *envp[])
{
	char	*path;
	char	**split_paths;
	char	special_c[2];

	special_c[0] = '\'';
	special_c[1] = '\0';
	path = find_path(envp);
	split_paths = ft_split(path, ':', special_c);
	if (path == NULL || split_paths == NULL)
		error("path spliting error");
	return (split_paths);
}
