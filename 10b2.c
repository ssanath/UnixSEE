#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int cpid1 = fork();
	int cpid2 = fork();
	int status;
	if(cpid1 != 0 && cpid2 != 0)
	{
		printf("Parent process is waiting for child: %d\n", cpid2);
		int waitPID = 0;
		while(waitPID == 0)
		{
			waitPID = waitpid(cpid2,&status,WNOHANG);
		}
		printf("Parent waited for child: %d\n", waitPID);
		printf("Child exited with status %d\n", WEXITSTATUS(status));
	}
	else if(cpid1 == 0 && cpid2 != 0)
	{
		printf("Child1: %d\n", getpid());
		exit(1);
	}
	else if(cpid1 != 0 && cpid2 == 0)
	{
		printf("Child2: %d\n", getpid());
		exit(2);
	}
	else
	{
		printf("Child3: %d\n", getpid());
		exit(3);
	}
	return 0;
}
