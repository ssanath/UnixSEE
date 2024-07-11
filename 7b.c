#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	int fd1 = open(argv[1],O_RDWR,0);
	int fd2 = open(argv[2],O_RDWR,0);
	char buf[50];
	int size = lseek(fd1,0,SEEK_END);
	lseek(fd1,0,SEEK_SET);
	read(fd1,buf,sizeof(buf));
	if(write(fd2,buf,size) != size)
	{
		perror("Error in writing\n");
		exit(1);
	}
	else
	{
		printf("File copied successfully\n");
	}
	return 0;
}
