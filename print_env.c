#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	printf("USER: %s\n", getenv("USER"));
	printf("PATH: %s\n", getenv("PATH"));
	printf("HOME: %s\n", getenv("HOME"));
	return 0;
}
