#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		perror("Incorrect number of arguments have been given\n");
		exit(1);
	}
	struct stat fileStat;
	if(stat(argv[1],&fileStat) < 0)
	{
		perror("Error\n");
		exit(1);
	}
	printf("File: %s\n", argv[1]);
	printf("Size: %d\n", fileStat.st_size);
	printf("No of links: %d\n", fileStat.st_nlink);
	printf("File inode: %d\n", fileStat.st_ino);
	
	printf("File permissions:\n");
	printf("Is a directory: %s\n",(S_ISDIR(fileStat.st_mode))?"Yes":"No");
	printf((fileStat.st_mode & S_IRUSR)?"r\n":"-\n");
	printf((fileStat.st_mode & S_IWUSR)?"w\n":"-\n");
	printf((fileStat.st_mode & S_IXUSR)?"x\n":"-\n");
	printf((fileStat.st_mode & S_IRGRP)?"r\n":"-\n");
	printf((fileStat.st_mode & S_IWGRP)?"w\n":"-\n");
	printf((fileStat.st_mode & S_IXGRP)?"x\n":"-\n");
	printf((fileStat.st_mode & S_IROTH)?"r\n":"-\n");
	printf((fileStat.st_mode & S_IWOTH)?"w\n":"-\n");
	printf((fileStat.st_mode & S_IXOTH)?"x\n":"-\n");
	
	printf("The file %s a symbolic link\n",(S_ISLNK(fileStat.st_mode))?"is":"is not");
	return 0;
}
