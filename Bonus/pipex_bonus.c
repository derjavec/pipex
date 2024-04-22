/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 08:55:41 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/16 08:55:43 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_Bonus.h"

void	cmd_exc(int argc, char *argv[], t_bonus *cmd, char **split_paths)
{
	int	infile;
	int	outfile;

	if (cmd->i == 0)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
			heredoc(argv, cmd, split_paths, argc);
		else
		{
			infile = open(argv[1], O_RDONLY);
			if (infile < 0)
				error_bonus("Error opening input file", cmd, split_paths, argc);
			first_command(infile, cmd, split_paths, argc);
		}
	}
	if (cmd->i > 0 && cmd->i < argc - 4)
		middle_command(cmd, split_paths, argc);
	else if (cmd->i == argc - 4)
	{
		outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
		if (outfile < 0)
			error_bonus("Problems creating the outfile", cmd, split_paths,
				argc);
		last_command(outfile, cmd, split_paths, argc);
	}
}

void	pipex_bonus(int argc, char *argv[], char **split_paths, t_bonus *cmd)
{
	int	i;

	i = 0;
	while (i < argc - 3)
	{	
		cmd->i = i;
		if (i < argc - 4 && pipe(cmd->tube[i]) == -1)
			error_bonus("Error while piping", cmd, split_paths, argc);
		cmd->content[i] = pars_arg(argv[i + 2], split_paths, argc, cmd);
		cmd->pid[i] = fork();
		if (cmd->pid[i] < 0)
			error_bonus("fork error", cmd, split_paths, argc);
		if (cmd->pid[i] == 0)
			cmd_exc(argc, argv, cmd, split_paths);
		i++;
	}
	close_pipes(argc, cmd);
	i = 0;
	while (i < argc - 3)
		waitpid(cmd->pid[i++], NULL, 0);
}

void	check_arg(int argc, char *argv[])
{
	int	i;

	if (argc < 5)
		error("Wrong amount of arguments");
	i = 0;
	while (argv[i])
	{
		if (!argv[i] || !argv[i][0])
			error("Empty argument\n");
		i++;
	}
	return ;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_bonus	*cmd;
	char	**split_paths;

	check_arg(argc, argv);
	split_paths = pars_path(envp);
	cmd = malloc(sizeof(t_bonus));
	if (cmd == NULL)
		error_bonus("Malloc error for cmd", cmd, split_paths, argc);
	ft_initialize_null(cmd);
	cmd->tube = malloc((argc - 3) * sizeof(*cmd->tube));
	if (cmd->tube == NULL)
		error_bonus("Malloc error for fd", cmd, split_paths, argc);
	cmd->content = malloc((argc - 2) * sizeof(char **));
	if (cmd->content == NULL)
		error_bonus("Malloc error for content", cmd, split_paths, argc);
	ft_initialize_content_null(cmd, argc);
	cmd->pid = malloc((argc - 3) * sizeof(pid_t));
	if (cmd->pid == NULL)
		error_bonus("Malloc error for pid", cmd, split_paths, argc);
	pipex_bonus(argc, argv, split_paths, cmd);
	free_all_bonus(cmd, split_paths);
	return (EXIT_SUCCESS);
}
