/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:28:27 by aguinea           #+#    #+#             */
/*   Updated: 2024/12/16 20:23:25 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdbool.h>

int		main(int ac, char **av, char **env);
char	*my_getenv(char **env);
void	child_process(char	**spl, char **env, char **av, int *pfd);
char	*get_def_path(char **splt, char	*command);
int		ft_open(char *file, int flag);
void	parent_process(char	**spl, char **env, char **av, int *pfd);
void	free_arr(char **arr);
void	my_error(int i);
#endif
