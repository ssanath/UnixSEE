#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	int src,dest;
	char buf[30];
	src = open("source.txt",O_RDONLY,0);
	if(src < 0)
	{
		perror("Could not open the source file\n");
		exit(1);
	}
	dest = open("destination.txt",O_CREAT | O_TRUNC | O_RDWR,0);
	if(dest < 0)
	{
		perror("Could not open the destination file\n");
		exit(1);
	}
	int size = lseek(src,0,SEEK_END);
	
	for(int i=size-1;i>=0;i--)
	{
		lseek(src,i,SEEK_SET);
		
		int n = read(src,buf,1);
		if(n != 1)
		{
			perror("Read error\n");
			exit(1);
		}
		
		n = write(dest,buf,1);
		if(n != 1)
		{
			perror("Write error\n");
			exit(1);
		}
		
	}
	return 0;
}
