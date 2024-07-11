#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main()
{
	struct stat fileStat;
	if(stat("foo.txt",&fileStat))
	{
		perror("stat error\n");
		exit(1);
	}
	if(chmod("foo.txt",(fileStat.st_mode & ~S_IXGRP) | S_ISGID) < 0)
	{
		printf("chmod error\n");
		exit(1);
	}
	if(chmod("bar.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
	{
		printf("chmod error\n");
		exit(1);
	}
	return 0;
}
