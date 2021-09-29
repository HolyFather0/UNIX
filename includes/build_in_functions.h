#ifndef MINISHELL_BUILD_IN_FUNCTIONS_H
# define MINISHELL_BUILD_IN_FUNCTIONS_H

# include <stdlib.h>
# include "libft.h"

int		check_identifier(char *str);
int		echo(int argc, char **argv);
int		pwd();
int		unset(int argc, char **argv, char **envp);
int		env(char **envp);
int		export(int argc, char **argv, char ***envp);
int		cd(int argc, char **argv, char ***envp);
int		exit_build_in(int argc, char **argv, int pipe, int exit_code);
void	export_work_envp(char **argv, int i, char ***envp);
void	print_error_export(const char *str);
int     wc(int argc, char **argv);
int     chmod_build_in(int argc, char **argv);
int     du();

#endif
