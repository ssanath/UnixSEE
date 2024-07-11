#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#define SHARED_MEM_SIZE sizeof(int)

int main()
{
	int fd,*offset_ptr;
	char *write_buffer = "This is writen by the parent process\n";
	char read_buf[100];
	fd = open("shared_file.txt",O_RDWR,0666);
	int shm_fd = shm_open("offset_shm",O_RDWR | O_CREAT | O_TRUNC,0666);
	ftruncate(shm_fd,SHARED_MEM_SIZE);
	offset_ptr = mmap(NULL,SHARED_MEM_SIZE,PROT_READ | PROT_WRITE,MAP_SHARED,shm_fd,0);
	if(offset_ptr == MAP_FAILED)
	{
		perror("Error\n");
		exit(1);
	}
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork error\n");
		exit(1);
	}
	else if(pid == 0)
	{
		printf("Child process has started\n");
		lseek(fd,*offset_ptr,SEEK_SET);
		int bytes_read = read(fd,read_buf,sizeof(read_buf));
		if(bytes_read > 0)
		{
			read_buf[bytes_read] = '\0';
			printf("Child process read %d bytes of data: %s\n", bytes_read,read_buf);
		}
		else
		{
			perror("Read error\n");
			exit(1);
		}
		*offset_ptr = lseek(fd,0,SEEK_CUR);
		printf("Child process has finished\n");
	}
	else
	{
		printf("Parent process has started\n");
		write(fd,write_buffer,strlen(write_buffer));
		*offset_ptr = lseek(fd,0,SEEK_CUR);
		printf("Parent process has finished\n");
	}
	munmap(offset_ptr,SHARED_MEM_SIZE);
	close(shm_fd);
	close(fd);
	return 0;
}
