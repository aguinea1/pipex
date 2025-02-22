/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:21:22 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/29 00:55:40 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

# include "../../mandatory/include/pipex.h"
# include "../../mandatory/libft/libft.h"

typedef struct s_pipex
{
	int	in;
	int	out;
}	t_pipex;

int		main(int ac, char **av, char **env);
char	*my_getenv(char **env);
void	here_doc_pfd(char *limit);
void	here_doc(char *limit, int *pfd);
#endif
