/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:55:19 by aguinea           #+#    #+#             */
/*   Updated: 2024/12/20 11:30:03 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/include/pipex.h"
#include "../mandatory/libft/libft.h"

void	my_error(int i)
{
	i = 0;
	ft_printf("./pipex infile cmd cmd outfile\n");
	exit (1);
}

int	ft_open(char *file, int flag)
{
	int	fd;

	fd = 0;
	if (flag == 1)
		fd = open (file, O_RDONLY, 0777);
	else if (flag == 0)
		fd = open (file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd == -1)
		exit(1);
	return (fd);
}

char	*get_def_path(char **splt, char	*command)
{
	int		i;
	char	*final_path;
	char	*path;

	i = 0;
	while (splt[i])
	{
		path = ft_strjoin(splt[i], "/");
		final_path = ft_strjoin(path, command);
		if (access(final_path, F_OK | X_OK) == 0)
		{
			free(path);
			return (final_path);
		}
		i++;
		free (final_path);
		free (path);
	}
	return (final_path);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
