#define _POSIX
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
typedef struct dirent Dirent;
DIR* fd;
Dirent* dp;
int main(int argc,char* argv[])
{
	if(argc<2)
		perror("No Directory Name specifoed...");
	else
	{
		fd=opendir(argv[1]);
		if(fd==NULL)
			perror("Unable to open the Directoryu File...");
		while(dp=readdir(fd))
			printf("%s \t",dp->d_name);
	}
	return 0;
}
