#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int status;
	pid_t pid = fork();
	
	if(pid < 0)
	{
		perror("Fork error\n");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0)
	{
		printf("Child process has started\n");
		char *args[] = {"./interpreter","arg1","arg2",NULL};
		char *env[] = {"VAR1=value1","VAR2=value2",NULL};
		
		execve(args[0],args,env);
		perror("execve\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid,&status,0);
		
		printf("Parent process has started\n");
		char *args[] = {"./interpreter","arg4","arg3",NULL};
		
		execvp(args[0],args);
		perror("execve\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}
