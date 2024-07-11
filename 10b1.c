#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("Fork error\n");
		exit(1);
	}
	else if(pid == 0)
	{
		printf("Child process is executing\n");
	}
	else
	{
		printf("Parent process is executing\n");
		int cpid = wait(NULL);
		printf("Parent: %d\n", getpid());
		printf("Child: %d\n", cpid);
	}
	return 0;
}
