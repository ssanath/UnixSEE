#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if(access(argv[1],F_OK) == 0)
	{
		printf("%s can be accessed\n", argv[1]);
	}
	else
	{
		printf("%s cannot be accessed\n", argv[1]);
	}
	return 0;
}
