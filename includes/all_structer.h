#ifndef MINISHELL_ALL_STRUCTER_H
# define MINISHELL_ALL_STRUCTER_H

typedef struct		s_execv {
	int		stdin_back;
	int		stdout_back;
	t_shell **shell;
	char	**envp;
	int		exit_status;
	int		count_pipe;
}					t_execv;

#endif
