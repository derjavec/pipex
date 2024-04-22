/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:44:19 by derjavec          #+#    #+#             */
/*   Updated: 2024/02/14 13:44:21 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_Bonus.h"

int	ft_max(const char *str1, const char *str2)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 > len2)
		return (len1);
	else
		return (len2 - 1);
}

void	heredoc(char **argv, t_bonus *cmd, char **split_paths, int argc)
{
	char	*line;
	int		temp_fd[2];

	if (pipe(temp_fd) == -1)
		error_bonus("Error while piping", cmd, split_paths, argc);
	dup2(cmd->tube[cmd->i][1], temp_fd[1]);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, argv[2], ft_max(argv[2], line)) == 0)
		{
			close(temp_fd[1]);
			exit(EXIT_SUCCESS);
		}
		write(temp_fd[1], line, ft_strlen(line));
		free(line);
	}
}
