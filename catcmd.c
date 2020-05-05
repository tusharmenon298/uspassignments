#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<fcntl.h>
int main(int argc, char* argv[])
{	
	int n,dest,i=1;
	char buffer[8];
	if(argc<2)
	{
		printf("Please enter a file \n");
		return 1;
	}
	while(i<argc)
	{
		dest=open(argv[i],O_RDONLY);
		if(dest==-1)
		{
			printf("Error Occured While Opening File\n");
			return 1;
		}
		while((n=read(dest,buffer,8))>0)
		{
			printf("%s",buffer);
		}
		memset(buffer,0,8);
		close(dest);
		i++;
	}
	return 0;
}

