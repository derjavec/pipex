/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:38:58 by derjavec          #+#    #+#             */
/*   Updated: 2024/02/12 09:39:00 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../pipex.h"

void	error_bonus(const char *msg, t_bonus *cmd, char **split_paths,
			int argc)
{
	int	j;

	j = 0;
	while (j < argc - 4)
	{
		if (cmd && cmd->tube[j] && cmd->tube[j][0])
			close(cmd->tube[j][0]);
		j++;
	}
	j = 0;
	while (j < argc - 4)
	{
		if (cmd && cmd->tube[j] && cmd->tube[j][1])
			close(cmd->tube[j][1]);
		j++;
	}
	free_all_bonus(cmd, split_paths);
	perror(msg);
	exit(EXIT_FAILURE);
}
