#include "minishell.h"

static int	norm_helper(t_execv *all, t_shell *command, int func, int pipe)
{
	if (func == 5) {
		return (exit_build_in(size_of_2d_array(command->argv) - 1,
							&(command->argv[1]), pipe, all->exit_status));
	}
	else if (func == 6) {
		return (export(size_of_2d_array(command->argv) - 1,
				&(command->argv[1]), &(all->envp)));
	}
	else if (func == 7) {
		return (unset(size_of_2d_array(command->argv) - 1,
					&(command->argv[1]), all->envp));
	}
    else if (func == 8) {
        return (wc(size_of_2d_array(command->argv) - 1,
                   &(command->argv[1])));
    }
    else if (func == 9) {
        return (chmod_build_in(size_of_2d_array(command->argv) - 1,
                               &(command->argv[1])));
    }
    else if (func == 10) {
        return du();
    }
	return (-1);
}

int			call_build_in(t_execv *all, t_shell *command, int func, int pipe)
{
	if (func == 1)
	{
		return (echo(size_of_2d_array(command->argv) - 1,
				&(command->argv[1])));
	}
	else if (func == 2)
		return (pwd());
	else if (func == 3)
	{
		return (cd(size_of_2d_array(command->argv) - 1,
			&(command->argv[1]), &(all->envp)));
	}
	else if (func == 4)
		return (env(all->envp));
	else
		return (norm_helper(all, command, func, pipe));
}

int			is_build_in(char *str)
{
	if (!ft_strncmp(str, "echo", 10))
		return (1);
	else if (!ft_strncmp(str, "pwd", 10))
		return (2);
	else if (!ft_strncmp(str, "cd", 10))
		return (3);
	else if (!ft_strncmp(str, "env", 10))
		return (4);
	else if (!ft_strncmp(str, "exit", 10))
		return (5);
	else if (!ft_strncmp(str, "export", 10))
		return (6);
	else if (!ft_strncmp(str, "unset", 10))
		return (7);
    else if (!ft_strncmp(str, "wc", 10))
        return (8);
    else if (!ft_strncmp(str, "chmod", 10)) {
        return 9;
    }
    else if (!ft_strncmp(str, "du", 10)) {
        return 10;
    }
	return (0);
}
