#include "minishell.h"

void	make_fd(t_shell *command)
{
	if (command->input != 0)
		if (dup2(command->input, 0) == -1)
			dup2_fail();
	if (command->output != 1)
		if (dup2(command->output, 1) == -1)
			dup2_fail();
}

void	return_input_output(t_execv *all, t_shell *command)
{
	if (command->input != 0)
	{
		close(command->input);
		close(0);
		if (dup2(all->stdin_back, 0) == -1)
			dup2_fail();
	}
	if (command->output != 1)
	{
		close(command->output);
		close(1);
		if (dup2(all->stdout_back, 1) == -1)
			dup2_fail();
	}
}
