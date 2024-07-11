#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>

int my_function(char *command)
{
	if(command == NULL)
	{
		return -1;
	}
	
	pid_t pid = fork();
	
	if(pid < 0)
	{
		perror("Fork error\n");
		return -1;
	}
	else if(pid == 0)
	{
		execl("/bin/sh","sh","-c",command,(char *)NULL);
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;
		if(waitpid(pid,&status,0) < 0)
		{
			return -1;
		}
		if(WIFEXITED(status))
		{
			return WEXITSTATUS(status);
		}
		else
		{
			return -1;
		}
	}
}

int main()
{
	int result;
	printf("Executing ls -l command\n");
	result = my_function("ls -l");
	
	if(result == -1)
	{
		perror("Error executing ls -l\n");
		exit(1);
	}
	else
	{
		printf("Command executed successfully\n");
	}
	return 0;
}
