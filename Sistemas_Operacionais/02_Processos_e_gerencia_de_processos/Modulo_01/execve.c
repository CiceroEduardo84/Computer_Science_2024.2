#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv, char *envp[])
{
  int pid, i;

  for (i = 1; i <= 3; i++)
  {
    pid = fork();
    if (pid < 0)
    {
      printf("Algo deu errado!!!\n");
      return 0;
    }
    if (pid == 0)
    { // Processo filho
      if (i == 1)
        execve("/usr/bin/xcalc", argv, envp);
      if (i == 2)
        execve("/usr/bin/gedit", argv, envp);
      if (i == 3)
        execve("/usr/bin/xeyes", argv, envp);
    }
    else // Processo pai
      waitpid(pid, NULL, 0)
  }
}