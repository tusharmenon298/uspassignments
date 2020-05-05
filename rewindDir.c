//rewinddir() api
#define _POSIX
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<stdlib.h>
#include<sys/dir.h>
#include<sys/stat.h>
#include<sys/types.h>
typedef struct direct Dirent;
DIR* fd;
Dirent* dp;
int main(int argc,char* argv[])
{
	if(argc<2)
		perror("Directory name not specified...");
	else
	{
		fd=opendir(argv[1]);
		for(int i=1;i<=2;i++)
		{
			if(i==1)
				printf("\n\nPrinting the contents of the directory %s first time: ",argv[1]);
			if(i==2)
				printf("\n\nPrinting the contents of the directory %s second time: ",argv[1]);
			while(dp=readdir(fd))
				printf("%s\t",dp->d_name);
			rewinddir(fd);
		}
	}
	return 0;
}
