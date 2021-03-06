#include "minishell.h"

char		*ft_make_new_substr(char const *start, char const *end)
{
	char *substr;
	char *tmp;

	substr = (char *)malloc((end - start) + 2);
	tmp = substr;
	while (start != end)
	{
		*substr = *start;
		substr++;
		start++;
	}
	*substr = '\0';
	return (tmp);
}

int			sh_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return (0);
	write(fd, s, ft_strlen(s));
	return (0);
}
