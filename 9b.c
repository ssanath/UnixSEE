#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int fd = open(argv[1],O_RDWR,0);
	char buf[50];
	read(fd,buf,20);
	printf("First 20 characters:\n");
	write(STDOUT_FILENO,buf,20);
	printf("\n");
	lseek(fd,10,SEEK_SET);
	printf("After seeking 10 bytes from the beginning\n");
	read(fd,buf,20);
	write(STDOUT_FILENO,buf,20);
	printf("\n");
	lseek(fd,10,SEEK_CUR);
	printf("After seeking 10 bytes from the current position\n");
	read(fd,buf,20);
	write(STDOUT_FILENO,buf,20);
	printf("\n");
	int size = lseek(fd,0,SEEK_END);
	printf("File size is %d bytes\n", size);
	return 0;
}
