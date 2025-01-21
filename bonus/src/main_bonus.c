/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:34:20 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/21 18:43:16 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/loop.h"


char    *my_getenv(char **env)
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

static	void	my_exec(char *def_path, char **cmd, char **env)
{
	if (execve(def_path, cmd, env) == -1)
	{
		ft_printf("pipex: command not found : ", 27);
		free_arr(cmd);
		exit(127);
	}
	free_arr(cmd);
}

static void		parent(char *cmnds, char **env)
{
	char	**cmd;
	char	*def_path;
	char **spl;

	spl = ft_split(my_getenv(env), ':');
	cmd = ft_split(cmnds, ' ');
	def_path = get_def_path(spl, cmd[0]);
	my_exec(def_path, cmd, env);
}

static	void	child(char *cmnds, int *pfd, char **env, int out)
{
	pid_t	pid;
	char	**cmd;
	char	*def_path;
	char **spl;

	spl = ft_split(my_getenv(env), ':');
	cmd = ft_split(cmnds, ' ');
	def_path = get_def_path(spl, cmd[0]);
	pid = fork();
	if (pid == -1)
		exit (1);
	if (!pid)
	{
		close(pfd[0]);
		dup2(out, 0);
		dup2(pfd[1], 1);
		close(pfd[1]);
		my_exec(def_path, cmd, env);
	}
	else
	{
		dup2(pfd[0], 0);
		close(pfd[1]);
		close(pfd[0]);
	}
}

int 	main(int ac, char **av, char **env)
{
	int		in;
	int		out;
	int		i;
	int		status;
	int		pfd[2];

	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{}
	else
	{
		out = ft_open(av[1], 1);
		in = ft_open(av[ac - 1], 0);
	}
	i = 2;
	while (i++ < ac - 2)
	{
		child(av[i], pfd, env, out);
		pfd[0] = pfd[1];

	}
	while (wait(&status) > 0);

	dup2(in, 1);
	parent(av[ac - 2], env);
}



