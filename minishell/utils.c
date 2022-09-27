#include "minishell.h"

int	ft_filesize(t_redirection *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (!ft_strcmp(lst->redir, "<") || !ft_strcmp(lst->redir, ">")
			|| !ft_strcmp(lst->redir, ">>"))
			i++;
		lst = lst->next;
	}
	return (i);
}

int	ft_matrix_size(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

char	**ft_strdup_multi(char **s1)
{
	char	**dest;
	int		lines;
	int		i;

	i = -1;
	lines = ft_matrix_size(s1);
	dest = malloc(lines * (sizeof(char *) + 1));
	while (++i < lines)
		dest[i] = ft_strdup(s1[i]);
	dest[i] = 0;
	return (dest);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] < str2[i])
				return (-1);
			else
				return (1);
		}
		i++;
	}
	return (0);
}