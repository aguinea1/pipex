/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:29:13 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/29 01:03:14 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/pipex.h"
#include "../libft/libft.h"

void	parent_process(char	**spl, char **env, char **av, int *pfd)
{
	int		fd;
	char	*def_path;
	char	**command2;
	char	*outfile;
	char	*cmnds;

	outfile = av[4];
	cmnds = av[3];
	command2 = ft_split(cmnds, ' ');
	if (!command2 || !command2[0])
		my_error(3);
	fd = ft_open(outfile, 0);
	def_path = get_def_path(spl, command2[0]);
	dup2(fd, 1);
	dup2(pfd[0], 0);
	close (pfd[1]);
	if (execve(def_path, command2, env) == -1)
	{
		write(2, "pipex: command not found: ", 27);
		free_arr(command2);
		exit (1);
	}
	free_arr(command2);
}

static	void	error_static(char **command)
{
	ft_printf("pipex: command not found: %s\n ", command[0]);
	free_arr(command);
	exit(127);
}

void	child_process(char	**spl, char **env, char **av, int *pfd)
{
	int		fd;
	char	*def_path;
	char	**command1;
	char	*cmnds;
	char	*infile;

	cmnds = av[2];
	infile = av[1];
	command1 = ft_split(cmnds, ' ');
	if (!command1 || !command1)
		my_error(3);
	fd = ft_open(infile, 1);
	def_path = get_def_path(spl, command1[0]);
	if (!def_path)
		error_static(command1);
	dup2(fd, 0);
	dup2(pfd[1], 1);
	close (pfd[0]);
	if (execve(def_path, command1, env) == -1)
		error_static(command1);
	free_arr(command1);
}

char	*my_getenv(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (&env[i][5]);
		i++;
	}
	return (NULL);
}

int	main(int ac, char **av, char **env)
{
	pid_t	pid;
	char	**spl;
	int		pipefd[2];

	if (ac != 5)
		my_error(1);
	if (pipe(pipefd) == -1)
		exit(1);
	spl = ft_split(my_getenv(env), ':');
	pid = fork();
	if (pid == -1)
		exit(1);
	if (!pid)
		child_process(spl, env, av, pipefd);
	parent_process(spl, env, av, pipefd);
	return (0);
}
