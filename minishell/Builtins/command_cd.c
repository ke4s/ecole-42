#include "minishell_builtins.h"

void	command_cd_change_pwd(char ***exp, char ***env)
{
	int		env_pwd_line;
	char	*cwd;
	char	*new_pwd;
	char	*env_pwd;
	char	*old_pwd;

	cwd = getcwd(NULL, 0);
	env_pwd_line = find_line_char_matrix(*env, "PWD=", ENV_LIST, 4);
	if (env_pwd_line == -1)
		command_export(exp, env, "OLDPWD=");
	else
	{
		env_pwd = get_var_data(env[0][env_pwd_line]);
		old_pwd = ft_strjoin("OLDPWD=", env_pwd);
		command_export(exp, env, old_pwd);
		free_two_str(&env_pwd, &old_pwd);
	}
	new_pwd = ft_strjoin("PWD=", cwd);
	command_export(exp, env, new_pwd);
	free_two_str(&new_pwd, &cwd);
}

int	improved_chdir(char	*go_dir, char *incoming_dir)
{
	if (!incoming_dir)
		incoming_dir = go_dir;
	if (chdir(go_dir) == -1)
	{
		printf("cd: %s: No such file or directory\n", incoming_dir);
		return (-1);
	}
	return (0);
}

int	command_cd_tilde(char *dir, char ***exp, char ***env)
{
	int		home_index;
	char	*home_data;
	char	*go_dir;

	home_index = find_line_char_matrix(*env, "HOME=", ENV_LIST, 5);
	if (home_index == -1)
		return (-1);
	home_data = get_var_data(env[0][home_index]);
	if (ft_strncmp(dir, "~", 2) == 0)
	{
		if (improved_chdir(home_data, dir) == -1)
		{
			free(home_data);
			return (-1);
		}
	}
	else if (ft_strncmp(dir, "~/", 2) == 0)
	{
		go_dir = ft_strjoin(home_data, dir + 1);
		if (improved_chdir(go_dir, dir) == -1)
			return (free_two_str(&home_data, &go_dir));
	}
	else
		printf("cd: %s: No such file or directory\n", dir);
	free(home_data);
	return (0);
}

void	command_cd(char *dir, char ***exp, char ***env)
{
	if (!dir)
		return ;
	if (ft_strncmp(dir, "~", 1) == 0)
	{
		if (command_cd_tilde(dir, exp, env) == -1)
			return ;
	}
	else if (improved_chdir(dir, NULL) == -1)
		return ;
	command_cd_change_pwd(exp, env);
}
