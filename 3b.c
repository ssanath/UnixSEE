#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<time.h>

int main()
{
	int fd,n;
	struct dirent* dir;
	struct stat fileStat;
	DIR* dp;
	
	dp = opendir(".");
	
	if(dp)
	{
		while((dir = readdir(dp)) != NULL)
		{
			stat(dir->d_name,&fileStat);
			printf("%d %d %d %d %s %s\n", fileStat.st_ino, fileStat.st_mode, fileStat.st_uid, fileStat.st_gid, ctime(&fileStat.st_atime), dir->d_name);
		}
	}
	return 0;
}
