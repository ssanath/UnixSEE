#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>
#include<utime.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	struct utimbuf times;
	struct stat fileStat1, fileStat2;
	
	if(stat(argv[1],&fileStat1) < 0)
	{
		perror("Error\n");
		exit(1);
	}
	if(stat(argv[2],&fileStat2) < 0)
	{
		perror("Error\n");
		exit(1);
	}
	
	printf("Before copying:\n");
	
	printf("Access time: %s, Modification time: %s\n", ctime(&fileStat1.st_atime), ctime(&fileStat1.st_mtime));
	times.modtime = fileStat2.st_mtime;
	times.actime = fileStat2.st_atime;
	if(utime(argv[1],&times)<0)
	{
		perror("Error copying\n");
		exit(1);
	}
	if(stat(argv[1],&fileStat1) < 0)
	{
		perror("Error\n");
		exit(1);
	}
	
	printf("After copying:\n");
	
	printf("Access time: %s, Modification time: %s\n", ctime(&fileStat1.st_atime), ctime(&fileStat1.st_mtime));
	return 0;
}
