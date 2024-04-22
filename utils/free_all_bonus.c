/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:25:22 by derjavec          #+#    #+#             */
/*   Updated: 2024/02/12 09:25:24 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../pipex.h"

void	close_pipes(int argc, t_bonus *cmd)
{
	int	i;

	i = 0;
	while (i < argc - 4)
	{
		if (cmd && cmd->tube[i] && cmd->tube[i][1])
			close(cmd->tube[i][1]);
		if (cmd && cmd->tube[i] && cmd->tube[i][0])
			close(cmd->tube[i][0]);
		i++;
	}
	return ;
}

void	free_utils(t_bonus *cmd)
{
	int	i;
	int	j;

	if (cmd)
	{
		if (cmd->pid)
			free (cmd->pid);
		if (cmd->content)
		{
			i = 0;
			while (cmd->content[i])
			{
				j = 0;
				while (cmd->content[i][j])
					free(cmd->content[i][j++]);
				free(cmd->content[i]);
				i++;
			}
			free(cmd->content);
		}
		if (cmd->tube)
			free(cmd->tube);
		free(cmd);
	}
	return ;
}

void	free_all_bonus(t_bonus *cmd, char **split_paths)
{
	int	i;

	if (split_paths)
	{
		i = 0;
		while (split_paths[i])
		{
			free(split_paths[i]);
			i++;
		}
		free (split_paths);
	}
	free_utils(cmd);
	return ;
}
