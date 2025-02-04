/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:34:20 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/29 00:54:28 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/loop.h"

char	*my_getenv(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (&env[i][5]);
		i++;
	}
	return (NULL);
}

static	void	my_exec(char *cmnds, char **env)
{
	char	**cmd;
	char	*def_path;
	char	**spl;

	spl = ft_split(my_getenv(env), ':');
	cmd = ft_split(cmnds, ' ');
	if (!cmd || !cmd[0])
		my_error(3);
	def_path = get_def_path(spl, cmd[0]);
	if (!def_path)
	{
		ft_printf("pipex: command not found: %s\n", cmd[0]);
		free_arr(cmd);
		free_arr(spl);
		exit(127);
	}
	if (execve(def_path, cmd, env) == -1)
	{
		ft_printf("pipex: command not found : %s\n ", cmd[0]);
		free_arr(cmd);
		exit(127);
	}
	free_arr(cmd);
}

static	void	child(char *cmnds, int *pfd, char **env, int in)
{
	pid_t	pid;

	pipe(pfd);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		if (in == STDIN_FILENO)
			exit(1);
		else
			my_exec(cmnds, env);
	}
	else
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
	}
}

void	here_doc(char *limit, int *pfd)
{
	char	*line;

	close(pfd[0]);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strncmp(limit, line, ft_strlen(limit)) == 0)
		{
			free(line);
			exit (1);
		}
		ft_putstr_fd(line, pfd[1]);
		free (line);
		line = get_next_line(STDIN_FILENO);
	}
}

int	main(int ac, char **av, char **env)
{
	int		i;
	int		pfd[2];
	int		in;
	int		out;

	if (ac < 5)
		my_error(1);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac < 6)
			my_error(4);
		i = 3;
		out = ft_open(av[ac -1], 2);
		here_doc_pfd(av[2]);
	}
	else
	{
		i = 2;
		in = ft_open(av[1], 1);
		out = ft_open(av[ac - 1], 0);
		dup2(in, STDIN_FILENO);
	}
	while (i < ac - 2)
		child(av[i++], pfd, env, in);
	return (dup2(out, 1), my_exec(av[ac - 2], env), 0);
}
