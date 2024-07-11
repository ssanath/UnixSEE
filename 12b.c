#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>

int main()
{
	char *env[] = {"USER=child","PATH=/custom/path","HOME=home",NULL};
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("Fork error\n");
		exit(1);
	}
	else if(pid == 0)
	{
		execle("./print_env","print_env",NULL,env);
		perror("execle error\n");
		exit(1);
	}
	else
	{
		wait(NULL);
		execlp("./print_env","print_env",NULL);
	}
		
	return 0;
}
