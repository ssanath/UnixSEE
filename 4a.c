#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{
	if(argc == 3)
	{
		printf("Hard linking %s and %s\n", argv[1], argv[2]);
		if(link(argv[1],argv[2]) == 0)
		{
			printf("Hard link created\n");
		}
		else
		{
			printf("Unable to create a hard link\n");
		}
	}
	else if(argc == 4)
	{
		printf("Soft linking %s and %s\n", argv[1], argv[2]);
		if(symlink(argv[1],argv[2]) == 0)
		{
			printf("Soft link created\n");
		}
		else
		{
			printf("Unable to create a soft link\n");
		}
	}
	else
	{
		printf("Invalid number of parameter\n");
	}
	return 0;
}
