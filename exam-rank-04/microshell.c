#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int    print_error(char *str, char *cmd)
{
    int i=0;

    while (str[i])
        write(2, &str[i++], 1);
    if (cmd)
    {
        i = 0;
        while (cmd[i])
            write(2, &cmd[i++], 1);
    }
    write(2, "\n", 1);
    return (1);
}

void    ft_cd(char **argv, int i)
{
    if (i != 2)
        print_error("error: cd: bad arguments", NULL);
    else if (chdir(argv[1]) != 0)
        print_error("error: cd: cannot change directory to ", argv[1]);
}

void    ft_execute(char **argv, char **envp, int i, int flag)
{
    int fds[2];

    pipe(fds);
    if (fork() == 0)
    {
        close(fds[0]);
        if (!flag)
            dup2(fds[1], STDOUT_FILENO);
        close(fds[1]);
        argv[i] = NULL;
        execve(argv[0], argv, envp);
        print_error("error: cannot execute ", argv[0]);
        return ;
    }
    else
    {
        close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
    }
}

int main(int argc, char **argv, char **envp)
{
    int i=0, flag=0, cnt=0;
    int tmp_stdin, tmp_stdout;

    if (argc == 1)
        return (0);
    tmp_stdin = dup(STDIN_FILENO);
    tmp_stdout = dup(STDOUT_FILENO);
    while (argv[i] && argv[i + 1])
    {
        argv = &argv[i + 1];
        i = 0;
        while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
            i++;
        if (!strcmp(argv[0], "cd"))
            ft_cd(argv, i);
        else
        {
            if (i && (!argv[i] || !strcmp(argv[i], ";")))
                flag = 1;
			if (i)
				ft_execute(argv, envp, i, flag);
            cnt++;
        }
    }
    while (cnt-- > 0)
        waitpid(-1, NULL, 0);
    dup2(tmp_stdin, STDIN_FILENO);
    dup2(tmp_stdout, STDIN_FILENO);
    return (0);
}
