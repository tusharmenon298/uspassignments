//mkdir()
#define _POSIX
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
typedef struct dirent Dirent;
Dirent* dp;
DIR* fd;
int main(int argc,char* argv[])
{
	if(argc<2)
		perror("No Directory Name specified...");
	else
	{
		fd=opendir(argv[1]);
		if(fd==NULL)
			perror("Directory File cannot be opened....");
		printf("Before creating a new directory, contents of the directory: ");
		while(dp=readdir(fd))
		printf("%s \t",dp->d_name);
		if((mkdir(argv[2],S_IRWXU|S_IRWXG|S_IROTH|S_IWOTH|S_IXOTH))==-1)
			printf("New Directory %s cannot be created...",argv[2]);
		else
		{
			rewinddir(fd);
			printf("\n New directory %s is created\n",argv[2]);
			printf("After creating the directtory, contents of the directory: ");
			while(dp=readdir(fd))
				printf("%s \t",dp->d_name);
		}
	}
return 0;
}
