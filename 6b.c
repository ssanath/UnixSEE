#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	int fd = open(argv[1],O_RDWR,0);
	struct flock fvar;
	char buf[100];
	fvar.l_type = F_WRLCK;
	fvar.l_whence = SEEK_END;
	fvar.l_start = SEEK_END-100;
	fvar.l_len = 100;
	printf("Press ENTER to lock\n");
	getchar();
	if(fcntl(fd,F_SETLK,&fvar) == -1)
	{
		fcntl(fd,F_GETLK,&fvar);
		printf("File already locked by process: %d\n", fvar.l_pid);
		return -1;
	}
	printf("Locked\n");
	
	lseek(fd,-50,SEEK_END);
	read(fd,buf,50);
	printf("Read the last 50 bytes\n");
	puts(buf);
	printf("Press ENTER to unlock\n");
	getchar();
	
	fvar.l_type = F_UNLCK;
	fvar.l_whence = SEEK_SET;
	fvar.l_start = 0;
	
	if(fcntl(fd,F_UNLCK,&fvar) == -1)
	{
		perror("Could not unlock\n");
		exit(1);
	}
	printf("Unlocked\n");
	close(fd);
	return 0;
}
