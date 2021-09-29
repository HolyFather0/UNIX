#include "exit.h"

void	exit_malloc(void)
{
	ft_putendl_fd(strerror(errno), 2);
	exit(1);
}

void	exit_fork(void)
{
	ft_putendl_fd("can not create fork", 2);
	exit(1);
}

int		error_fork(void)
{
	ft_putstr_fd("minishell: fork: ", 2);
	ft_putendl_fd(strerror(errno), 2);
	return (1);
}
