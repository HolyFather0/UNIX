#ifndef MINISHELL_SIGNAL_MINISHELL_H
# define MINISHELL_SIGNAL_MINISHELL_H

# include <signal.h>

void	signal_init();
void	signal_quit(int signal);
void	signal_int(int signal);
void	signal_proc(int signal);
void	signal_quit_fork(int signal);

#endif
