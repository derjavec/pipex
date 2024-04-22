/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 08:56:59 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/16 08:57:01 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include "./utils/gnl/get_next_line.h"

typedef struct s_bonus
{
	int				i;
	char			***content;
	int				(*tube)[2];
	pid_t			*pid;
}	t_bonus;

int		ft_strncmp(const char *first, const char *second, size_t length);
char	**ft_split(char *s, char c, char *e);
char	*ft_copylettres_reduc(char **tableau, int mot, int lettres, char *s);
char	*ft_copylettres(char **tableau, int mot, char *s, char **ce);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup( const char *src);
size_t	ft_strlen( const char *c);
char	*ft_strchr(const char *str, int c);
char	*find_path(char *envp[]);
char	**pars_path(char *envp[]);
char	**pars_arg(char *str, char **split_paths, int argc, t_bonus *cmd);
void	error(const char *msg);
void	free_all_bonus(t_bonus *cmd, char **split_paths);
void	error_bonus(const char *msg, t_bonus *cmd, char **split_paths,
			int argc);
void	ft_initialize_content_null(t_bonus *cmd, int argc);
void	ft_initialize_null(t_bonus *cmd);
void	first_command(int infile, t_bonus *cmd, char **split_paths, int argc);
void	middle_command(t_bonus *cmd, char **split_paths, int argc);
void	last_command(int outfile, t_bonus *cmd, char **split_paths, int argc);

#endif
