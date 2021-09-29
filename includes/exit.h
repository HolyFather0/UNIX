#ifndef MINISHELL_EXIT_H
# define MINISHELL_EXIT_H

# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include "libft.h"

void	exit_malloc();
void	dup_fail();
void	dup2_fail();
void	exit_fork();
void	print_error(char *buf);
void	print_error_fork(char *buf);
int		error_fork(void);

#endif
