#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main()
{
	int status;
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("Fork error\n");
		exit(1);
	}
	else if(pid == 0)
	{
		printf("Child process is executing: %d\n", getpid());
		execl("./program","program","source.txt",(char *)NULL);
		perror("execl\n");
		exit(1);
	}
	else
	{
		printf("Parent process is executing: %d\n", getpid());
		waitpid(pid,&status,0);
	}
	return 0;
}
