/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:05:53 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/17 09:05:55 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../pipex.h"

void	error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}