#include "exit.h"

void	dup_fail(void)
{
	ft_putendl_fd("dup failed to back up stdin or stdout", 2);
	exit(1);
}

void	dup2_fail(void)
{
	ft_putendl_fd("dup2 failed", 2);
	exit(1);
}
