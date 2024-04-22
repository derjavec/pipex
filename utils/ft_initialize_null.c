/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_null.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:04:24 by derjavec          #+#    #+#             */
/*   Updated: 2024/02/19 10:04:26 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../pipex.h"

void	ft_initialize_content_null(t_bonus *cmd, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		cmd->content[i] = NULL;
		i++;
	}
	return ;
}

void	ft_initialize_null(t_bonus *cmd)
{
	if (cmd)
	{
		cmd->i = 0;
		cmd->content = NULL;
		cmd->tube = NULL;
		cmd->pid = NULL;
	}
	return ;
}
