/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:44:05 by aguinea           #+#    #+#             */
/*   Updated: 2025/01/29 00:40:46 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/loop.h"

void	here_doc_pfd(char *limit)
{
	pid_t	pid;
	int		pfd[2];

	if (pipe(pfd) == -1)
		exit (0);
	pid = fork();
	if (pid == -1)
		exit (0);
	if (!pid)
		here_doc(limit, pfd);
	else
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		wait(NULL);
	}
}
