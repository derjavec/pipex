/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:51:53 by derjavec          #+#    #+#             */
/*   Updated: 2024/02/14 10:51:54 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../pipex.h"

void	command_exc(t_bonus *cmd, char **split_paths, int argc)
{
	int		j;
	char	*path_cmd1;
	char	*path_cmd1b;

	j = 0;
	while (split_paths[j])
	{
		path_cmd1 = ft_strjoin(split_paths[j], "/");
		path_cmd1b = ft_strjoin(path_cmd1, cmd->content[cmd->i][0]);
		if (access(path_cmd1b, F_OK) == 0)
		{
			if (execve(path_cmd1b, cmd->content[cmd->i], NULL) == -1)
				error_bonus("execv error in child process", cmd, split_paths,
					argc);
		}
		free(path_cmd1);
		free(path_cmd1b);
		j++;
	}
	return ;
}

void	first_command(int infile, t_bonus *cmd, char **split_paths, int argc)
{
	close(cmd->tube[0][0]);
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		close(infile);
		error_bonus("dup error", cmd, split_paths, argc);
	}
	close(infile);
	if (dup2(cmd->tube[0][1], STDOUT_FILENO) == -1)
		error_bonus("dup error", cmd, split_paths, argc);
	close(cmd->tube[0][1]);
	command_exc(cmd, split_paths, argc);
	error_bonus("Command not found", cmd, split_paths, argc);
}

void	middle_command(t_bonus *cmd, char **split_paths, int argc)
{
	int	j;

	j = 0;
	while (j < cmd->i)
		close(cmd->tube[j++][1]);
	close(cmd->tube[cmd->i][0]);
	if (dup2(cmd->tube[cmd->i - 1][0], STDIN_FILENO) == -1)
		error_bonus("dup error", cmd, split_paths, argc);
	j = 0;
	while (j < cmd->i)
		close(cmd->tube[j++][0]);
	if (dup2(cmd->tube[cmd->i][1], STDOUT_FILENO) == -1)
		error_bonus("dup error", cmd, split_paths, argc);
	close(cmd->tube[cmd->i][1]);
	command_exc(cmd, split_paths, argc);
	error_bonus("Command not found", cmd, split_paths, argc);
}

void	last_command(int outfile, t_bonus *cmd, char **split_paths, int argc)
{
	int	j;

	j = 0;
	while (j < argc - 4)
		close(cmd->tube[j++][1]);
	if (dup2(cmd->tube[cmd->i - 1][0], STDIN_FILENO) == -1)
	{
		close(outfile);
		error_bonus("dup error", cmd, split_paths, argc);
	}
	j = 0;
	while (j < argc - 4)
		close(cmd->tube[j++][0]);
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		close(outfile);
		error_bonus("dup error", cmd, split_paths, argc);
	}
	close(outfile);
	command_exc(cmd, split_paths, argc);
	error_bonus("Command not found", cmd, split_paths, argc);
}
