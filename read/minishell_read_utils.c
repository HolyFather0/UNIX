#include "minishell.h"

void	eof_read_case(int flag, int exit_code, char **line)
{
	if (flag == 0 && **line == '\0')
		exit_build_in(0, NULL, 0, exit_code);
	if (flag == 0)
		ft_putstr_fd("  \b\b", 2);
}
