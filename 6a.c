#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	int fd1 = open("source.txt",O_RDWR,0);
	int fd2 = open("destination.txt",O_RDWR,0);
	char buf[20];
	printf("Before dup2:\n");
	printf("fd1: %d, fd2: %d\n", fd1, fd2);
	read(fd1,buf,5);
	fd1 = dup2(fd1,fd2);
	printf("After dup2:\n");
	printf("fd1: %d, fd2: %d\n", fd1, fd2);
	lseek(fd1,0,SEEK_END);
	write(fd1,buf,5);
	close(fd1);
	close(fd2);
	return 0;
}
