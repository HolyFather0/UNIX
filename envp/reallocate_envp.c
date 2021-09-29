#include "minishell.h"

char	**reallocate_envp(char **envp)
{
	char	**env;
	int		i;

	i = 0;
	env = (char **)malloc((size_of_2d_array(envp) + 1) * sizeof(char *));
	if (env == NULL)
		exit_malloc();
	while (envp[i] != NULL)
	{
		env[i] = ft_strdup(envp[i]);
		if (env[i] == NULL)
			exit_malloc();
		i++;
	}
	env[i] = NULL;
	return (env);
}
