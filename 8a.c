#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	struct stat fileStat;
	if(lstat(argv[1],&fileStat) < 0)
	{
		perror("lstat error\n");
		exit(1);
	}
	if(S_ISREG(fileStat.st_mode))
	{
		printf("Regular file\n");
	}
	else if(S_ISDIR(fileStat.st_mode))
	{
		printf("Directory file\n");
	}
	else if(S_ISCHR(fileStat.st_mode))
	{
		printf("Character special file\n");
	}
	else if(S_ISBLK(fileStat.st_mode))
	{
		printf("Block special file\n");
	}
	else if(S_ISFIFO(fileStat.st_mode))
	{
		printf("FIFO file\n");
	}
	else if(S_ISLNK(fileStat.st_mode))
	{
		printf("Symbolic link\n");
	}
	else if(S_ISSOCK(fileStat.st_mode))
	{
		printf("Socket file\n");
	}
	else
	{
		printf("Unknown mode\n");
	}
	return 0;
}
