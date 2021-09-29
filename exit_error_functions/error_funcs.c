#include "minishell.h"

void	print_error(char *buf)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(buf, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
}

void	print_error_fork(char *buf)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(buf, 2);
	ft_putstr_fd(": ", 2);
	if (errno == 2)
		ft_putendl_fd("command not found", 2);
	else
		ft_putendl_fd(strerror(errno), 2);
}
